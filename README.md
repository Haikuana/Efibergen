<p align="center">
  <a href="LICENSE" alt="GPLv3 license"><img src="https://img.shields.io/badge/license-GPLv3-brightgreen.svg" /></a>
  <a href="#" alt="no warranty"><img src="https://img.shields.io/badge/warranty-no-red.svg" /></a>
  <a href="https://joss.theoj.org/papers/add4f02dcedfaae8f81da200000d64ee"><img src="https://joss.theoj.org/papers/add4f02dcedfaae8f81da200000d64ee/status.svg"></a>
  <a href="https://zenodo.org/badge/latestdoi/140197063"><img src="https://zenodo.org/badge/140197063.svg" alt="DOI"></a>
</p>

# fibergen

A FFT-based homogenization tool, please refer original offical version for more details.

Install and build the 3rd-parties
```bash
sh configure.sh
sh build.sh
```

## Run

In order to test a data directory "data" from the command line directly, go back to the directory that is the parent of "data", and run: 
```bash
bash all.sh data
bash all.sh data 20
bash all.sh data 20 5e-3
```
where the last three arguments after all.sh are data resources, threads, and error threshold.
Note that, the name of the model file is important, especially ending with "_g_(resolution)".

To visualize the model as well, run:
```bash
bash gui.sh data
```
