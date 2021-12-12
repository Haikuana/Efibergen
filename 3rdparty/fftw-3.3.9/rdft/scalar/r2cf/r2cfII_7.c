/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Thu Dec 10 07:06:02 EST 2020 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cf.native -fma -compact -variables 4 -pipeline-latency 4 -n 7 -name r2cfII_7 -dft-II -include rdft/scalar/r2cfII.h */

/*
 * This function contains 24 FP additions, 18 FP multiplications,
 * (or, 9 additions, 3 multiplications, 15 fused multiply/add),
 * 23 stack variables, 6 constants, and 14 memory accesses
 */
#include "rdft/scalar/r2cfII.h"

static void r2cfII_7(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DK(KP692021471, +0.692021471630095869627814897002069140197260599);
     DK(KP801937735, +0.801937735804838252472204639014890102331838324);
     DK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DK(KP554958132, +0.554958132087371191422194871006410481067288862);
     DK(KP356895867, +0.356895867892209443894399510021300583399127187);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(28, rs), MAKE_VOLATILE_STRIDE(28, csr), MAKE_VOLATILE_STRIDE(28, csi)) {
	       E Td, Te, Tf, Tg, T3, T6, Tl, Tj, Th, T9;
	       Td = R0[0];
	       {
		    E T1, T2, T7, T8, T4, T5;
		    T1 = R0[WS(rs, 1)];
		    T2 = R1[WS(rs, 2)];
		    Te = T1 - T2;
		    T7 = R1[WS(rs, 1)];
		    T8 = R0[WS(rs, 2)];
		    Tf = T8 - T7;
		    T4 = R1[0];
		    T5 = R0[WS(rs, 3)];
		    Tg = T5 - T4;
		    T3 = T1 + T2;
		    T6 = T4 + T5;
		    Tl = FNMS(KP356895867, Te, Tg);
		    Tj = FNMS(KP356895867, Tf, Te);
		    Th = FNMS(KP356895867, Tg, Tf);
		    T9 = T7 + T8;
	       }
	       {
		    E Ta, Tm, Tb, Ti, Tc, Tk;
		    Ta = FMA(KP554958132, T9, T6);
		    Ci[WS(csi, 2)] = KP974927912 * (FNMS(KP801937735, Ta, T3));
		    Tm = FNMS(KP692021471, Tl, Tf);
		    Cr[WS(csr, 2)] = FNMS(KP900968867, Tm, Td);
		    Tb = FNMS(KP554958132, T3, T9);
		    Ci[WS(csi, 1)] = -(KP974927912 * (FNMS(KP801937735, Tb, T6)));
		    Ti = FNMS(KP692021471, Th, Te);
		    Cr[WS(csr, 1)] = FNMS(KP900968867, Ti, Td);
		    Cr[WS(csr, 3)] = Te + Tg + Tf + Td;
		    Tc = FMA(KP554958132, T6, T3);
		    Ci[0] = -(KP974927912 * (FMA(KP801937735, Tc, T9)));
		    Tk = FNMS(KP692021471, Tj, Tg);
		    Cr[0] = FNMS(KP900968867, Tk, Td);
	       }
	  }
     }
}

static const kr2c_desc desc = { 7, "r2cfII_7", { 9, 3, 15, 0 }, &GENUS };

void X(codelet_r2cfII_7) (planner *p) { X(kr2c_register) (p, r2cfII_7, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 7 -name r2cfII_7 -dft-II -include rdft/scalar/r2cfII.h */

/*
 * This function contains 24 FP additions, 18 FP multiplications,
 * (or, 12 additions, 6 multiplications, 12 fused multiply/add),
 * 20 stack variables, 6 constants, and 14 memory accesses
 */
#include "rdft/scalar/r2cfII.h"

static void r2cfII_7(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DK(KP222520933, +0.222520933956314404288902564496794759466355569);
     DK(KP623489801, +0.623489801858733530525004884004239810632274731);
     DK(KP433883739, +0.433883739117558120475768332848358754609990728);
     DK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DK(KP781831482, +0.781831482468029808708444526674057750232334519);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(28, rs), MAKE_VOLATILE_STRIDE(28, csr), MAKE_VOLATILE_STRIDE(28, csi)) {
	       E T1, Ta, Td, T4, Tb, T7, Tc, T8, T9;
	       T1 = R0[0];
	       T8 = R1[0];
	       T9 = R0[WS(rs, 3)];
	       Ta = T8 - T9;
	       Td = T8 + T9;
	       {
		    E T2, T3, T5, T6;
		    T2 = R0[WS(rs, 1)];
		    T3 = R1[WS(rs, 2)];
		    T4 = T2 - T3;
		    Tb = T2 + T3;
		    T5 = R1[WS(rs, 1)];
		    T6 = R0[WS(rs, 2)];
		    T7 = T5 - T6;
		    Tc = T5 + T6;
	       }
	       Ci[0] = -(FMA(KP781831482, Tb, KP974927912 * Tc) + (KP433883739 * Td));
	       Ci[WS(csi, 1)] = FNMS(KP974927912, Td, KP781831482 * Tc) - (KP433883739 * Tb);
	       Cr[0] = FMA(KP623489801, T4, T1) + FMA(KP222520933, T7, KP900968867 * Ta);
	       Ci[WS(csi, 2)] = FNMS(KP781831482, Td, KP974927912 * Tb) - (KP433883739 * Tc);
	       Cr[WS(csr, 2)] = FMA(KP900968867, T7, T1) + FNMA(KP623489801, Ta, KP222520933 * T4);
	       Cr[WS(csr, 1)] = FMA(KP222520933, Ta, T1) + FNMA(KP623489801, T7, KP900968867 * T4);
	       Cr[WS(csr, 3)] = T1 + T4 - (T7 + Ta);
	  }
     }
}

static const kr2c_desc desc = { 7, "r2cfII_7", { 12, 6, 12, 0 }, &GENUS };

void X(codelet_r2cfII_7) (planner *p) { X(kr2c_register) (p, r2cfII_7, &desc);
}

#endif
