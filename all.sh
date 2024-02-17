
#!/bin/bash
# Automatically read files and do the simulation with Fibergen
# Author: Haikuan Zhu
# data: 10/13/21

export PATH=$PATH:/home/hk/Documents/fibergen/fibergen_source/bin
export PYTHONPATH=$PYTHONPATH:/home/hk/Documents/fibergen/fibergen_source/lib

WriteFibergenArgus(){
if [ -f $1 ]; then
  rm $1
fi
filename=$1
Nthreads=$2
cubesize=$3
err=$4
cubefile=$5
echo "<settings>" >> "$filename"
echo "	<title>test cube</title>" >> "$filename"
echo "	<description>Example for loading a multi-phase material.</description>" >> "$filename"
echo "	<num_threads>$Nthreads</num_threads>" >> "$filename"
echo "	<solver n=\"$cubesize\">" >> "$filename"
echo "		<tol>$err</tol>" >> "$filename"
echo "		<materials>" >> "$filename"
echo "			<matrix E=\"0.001\" nu=\"0.001\" />" >> "$filename"
echo "			<plastic E=\"1.0\" nu=\"0.3\" />" >> "$filename"
echo "		</materials>" >> "$filename"
echo "		<gamma_scheme>staggered</gamma_scheme>" >> "$filename"
echo "	</solver>" >> "$filename"
echo "	<actions>" >> "$filename"
echo "		<read_raw_data material=\"plastic\" filename=\"$cubefile\" />" >> "$filename"
echo "		<calc_effective_properties />" >> "$filename"
echo "	</actions>" >> "$filename"
echo "</settings>" >> "$filename"
#echo "write fibergen input arguments done."
}

process_rawfile(){
#split filename
inpath=$1
IFS='/'  #delimiter
read -ra process0 <<< "$inpath" 
ndir=$((${#process0[@]}-1))
fullname=${process0[$ndir]}
IFS='.'  		
read -ra process1 <<< "$fullname" 
nla=$((${#process1[@]}-1))
le=$((${#process1[nla]}+1))
#echo "$le"
fname=${fullname::-$le}
IFS='_'  
read -ra process2 <<< "$fname" 
nlast=$((${#process2[@]}-1))
gridsize=${process2[$nlast]}
IFS=' '     # reset to default value after usage
#echo "$fullname $fname $gridsize"
}

#WriteFibergenArgus project.xml 20 163 data/cube163.raw

data_directory="data"
threads=20
errthres=5e-3

if [ $# -gt 0 ]; then
  data_directory=$1
 # echo $1
fi

if [ $# -gt 1 ]; then
  threads=$2
 # echo $2
fi

if [ $# -gt 2 ]; then
  errthres=$3
# echo $3
fi

#cd $data_directory
########main part
i=0
for entry in $data_directory/*
do
  files[$i]=$entry

  process_rawfile $entry
  
  outname="${fname}.xml"
  WriteFibergenArgus $outname $threads $gridsize $errthres $entry

  fibergen $outname

  echo "processing file: $entry with id: $i"
  i=$(($i + 1))
done
arraylength=${#files[@]}
#echo "${files[@]} "
echo "all done!!!!"

















