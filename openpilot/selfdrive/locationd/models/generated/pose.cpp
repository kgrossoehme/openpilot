#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_287223720192222431) {
   out_287223720192222431[0] = delta_x[0] + nom_x[0];
   out_287223720192222431[1] = delta_x[1] + nom_x[1];
   out_287223720192222431[2] = delta_x[2] + nom_x[2];
   out_287223720192222431[3] = delta_x[3] + nom_x[3];
   out_287223720192222431[4] = delta_x[4] + nom_x[4];
   out_287223720192222431[5] = delta_x[5] + nom_x[5];
   out_287223720192222431[6] = delta_x[6] + nom_x[6];
   out_287223720192222431[7] = delta_x[7] + nom_x[7];
   out_287223720192222431[8] = delta_x[8] + nom_x[8];
   out_287223720192222431[9] = delta_x[9] + nom_x[9];
   out_287223720192222431[10] = delta_x[10] + nom_x[10];
   out_287223720192222431[11] = delta_x[11] + nom_x[11];
   out_287223720192222431[12] = delta_x[12] + nom_x[12];
   out_287223720192222431[13] = delta_x[13] + nom_x[13];
   out_287223720192222431[14] = delta_x[14] + nom_x[14];
   out_287223720192222431[15] = delta_x[15] + nom_x[15];
   out_287223720192222431[16] = delta_x[16] + nom_x[16];
   out_287223720192222431[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7604442797155520121) {
   out_7604442797155520121[0] = -nom_x[0] + true_x[0];
   out_7604442797155520121[1] = -nom_x[1] + true_x[1];
   out_7604442797155520121[2] = -nom_x[2] + true_x[2];
   out_7604442797155520121[3] = -nom_x[3] + true_x[3];
   out_7604442797155520121[4] = -nom_x[4] + true_x[4];
   out_7604442797155520121[5] = -nom_x[5] + true_x[5];
   out_7604442797155520121[6] = -nom_x[6] + true_x[6];
   out_7604442797155520121[7] = -nom_x[7] + true_x[7];
   out_7604442797155520121[8] = -nom_x[8] + true_x[8];
   out_7604442797155520121[9] = -nom_x[9] + true_x[9];
   out_7604442797155520121[10] = -nom_x[10] + true_x[10];
   out_7604442797155520121[11] = -nom_x[11] + true_x[11];
   out_7604442797155520121[12] = -nom_x[12] + true_x[12];
   out_7604442797155520121[13] = -nom_x[13] + true_x[13];
   out_7604442797155520121[14] = -nom_x[14] + true_x[14];
   out_7604442797155520121[15] = -nom_x[15] + true_x[15];
   out_7604442797155520121[16] = -nom_x[16] + true_x[16];
   out_7604442797155520121[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7308623482707293882) {
   out_7308623482707293882[0] = 1.0;
   out_7308623482707293882[1] = 0.0;
   out_7308623482707293882[2] = 0.0;
   out_7308623482707293882[3] = 0.0;
   out_7308623482707293882[4] = 0.0;
   out_7308623482707293882[5] = 0.0;
   out_7308623482707293882[6] = 0.0;
   out_7308623482707293882[7] = 0.0;
   out_7308623482707293882[8] = 0.0;
   out_7308623482707293882[9] = 0.0;
   out_7308623482707293882[10] = 0.0;
   out_7308623482707293882[11] = 0.0;
   out_7308623482707293882[12] = 0.0;
   out_7308623482707293882[13] = 0.0;
   out_7308623482707293882[14] = 0.0;
   out_7308623482707293882[15] = 0.0;
   out_7308623482707293882[16] = 0.0;
   out_7308623482707293882[17] = 0.0;
   out_7308623482707293882[18] = 0.0;
   out_7308623482707293882[19] = 1.0;
   out_7308623482707293882[20] = 0.0;
   out_7308623482707293882[21] = 0.0;
   out_7308623482707293882[22] = 0.0;
   out_7308623482707293882[23] = 0.0;
   out_7308623482707293882[24] = 0.0;
   out_7308623482707293882[25] = 0.0;
   out_7308623482707293882[26] = 0.0;
   out_7308623482707293882[27] = 0.0;
   out_7308623482707293882[28] = 0.0;
   out_7308623482707293882[29] = 0.0;
   out_7308623482707293882[30] = 0.0;
   out_7308623482707293882[31] = 0.0;
   out_7308623482707293882[32] = 0.0;
   out_7308623482707293882[33] = 0.0;
   out_7308623482707293882[34] = 0.0;
   out_7308623482707293882[35] = 0.0;
   out_7308623482707293882[36] = 0.0;
   out_7308623482707293882[37] = 0.0;
   out_7308623482707293882[38] = 1.0;
   out_7308623482707293882[39] = 0.0;
   out_7308623482707293882[40] = 0.0;
   out_7308623482707293882[41] = 0.0;
   out_7308623482707293882[42] = 0.0;
   out_7308623482707293882[43] = 0.0;
   out_7308623482707293882[44] = 0.0;
   out_7308623482707293882[45] = 0.0;
   out_7308623482707293882[46] = 0.0;
   out_7308623482707293882[47] = 0.0;
   out_7308623482707293882[48] = 0.0;
   out_7308623482707293882[49] = 0.0;
   out_7308623482707293882[50] = 0.0;
   out_7308623482707293882[51] = 0.0;
   out_7308623482707293882[52] = 0.0;
   out_7308623482707293882[53] = 0.0;
   out_7308623482707293882[54] = 0.0;
   out_7308623482707293882[55] = 0.0;
   out_7308623482707293882[56] = 0.0;
   out_7308623482707293882[57] = 1.0;
   out_7308623482707293882[58] = 0.0;
   out_7308623482707293882[59] = 0.0;
   out_7308623482707293882[60] = 0.0;
   out_7308623482707293882[61] = 0.0;
   out_7308623482707293882[62] = 0.0;
   out_7308623482707293882[63] = 0.0;
   out_7308623482707293882[64] = 0.0;
   out_7308623482707293882[65] = 0.0;
   out_7308623482707293882[66] = 0.0;
   out_7308623482707293882[67] = 0.0;
   out_7308623482707293882[68] = 0.0;
   out_7308623482707293882[69] = 0.0;
   out_7308623482707293882[70] = 0.0;
   out_7308623482707293882[71] = 0.0;
   out_7308623482707293882[72] = 0.0;
   out_7308623482707293882[73] = 0.0;
   out_7308623482707293882[74] = 0.0;
   out_7308623482707293882[75] = 0.0;
   out_7308623482707293882[76] = 1.0;
   out_7308623482707293882[77] = 0.0;
   out_7308623482707293882[78] = 0.0;
   out_7308623482707293882[79] = 0.0;
   out_7308623482707293882[80] = 0.0;
   out_7308623482707293882[81] = 0.0;
   out_7308623482707293882[82] = 0.0;
   out_7308623482707293882[83] = 0.0;
   out_7308623482707293882[84] = 0.0;
   out_7308623482707293882[85] = 0.0;
   out_7308623482707293882[86] = 0.0;
   out_7308623482707293882[87] = 0.0;
   out_7308623482707293882[88] = 0.0;
   out_7308623482707293882[89] = 0.0;
   out_7308623482707293882[90] = 0.0;
   out_7308623482707293882[91] = 0.0;
   out_7308623482707293882[92] = 0.0;
   out_7308623482707293882[93] = 0.0;
   out_7308623482707293882[94] = 0.0;
   out_7308623482707293882[95] = 1.0;
   out_7308623482707293882[96] = 0.0;
   out_7308623482707293882[97] = 0.0;
   out_7308623482707293882[98] = 0.0;
   out_7308623482707293882[99] = 0.0;
   out_7308623482707293882[100] = 0.0;
   out_7308623482707293882[101] = 0.0;
   out_7308623482707293882[102] = 0.0;
   out_7308623482707293882[103] = 0.0;
   out_7308623482707293882[104] = 0.0;
   out_7308623482707293882[105] = 0.0;
   out_7308623482707293882[106] = 0.0;
   out_7308623482707293882[107] = 0.0;
   out_7308623482707293882[108] = 0.0;
   out_7308623482707293882[109] = 0.0;
   out_7308623482707293882[110] = 0.0;
   out_7308623482707293882[111] = 0.0;
   out_7308623482707293882[112] = 0.0;
   out_7308623482707293882[113] = 0.0;
   out_7308623482707293882[114] = 1.0;
   out_7308623482707293882[115] = 0.0;
   out_7308623482707293882[116] = 0.0;
   out_7308623482707293882[117] = 0.0;
   out_7308623482707293882[118] = 0.0;
   out_7308623482707293882[119] = 0.0;
   out_7308623482707293882[120] = 0.0;
   out_7308623482707293882[121] = 0.0;
   out_7308623482707293882[122] = 0.0;
   out_7308623482707293882[123] = 0.0;
   out_7308623482707293882[124] = 0.0;
   out_7308623482707293882[125] = 0.0;
   out_7308623482707293882[126] = 0.0;
   out_7308623482707293882[127] = 0.0;
   out_7308623482707293882[128] = 0.0;
   out_7308623482707293882[129] = 0.0;
   out_7308623482707293882[130] = 0.0;
   out_7308623482707293882[131] = 0.0;
   out_7308623482707293882[132] = 0.0;
   out_7308623482707293882[133] = 1.0;
   out_7308623482707293882[134] = 0.0;
   out_7308623482707293882[135] = 0.0;
   out_7308623482707293882[136] = 0.0;
   out_7308623482707293882[137] = 0.0;
   out_7308623482707293882[138] = 0.0;
   out_7308623482707293882[139] = 0.0;
   out_7308623482707293882[140] = 0.0;
   out_7308623482707293882[141] = 0.0;
   out_7308623482707293882[142] = 0.0;
   out_7308623482707293882[143] = 0.0;
   out_7308623482707293882[144] = 0.0;
   out_7308623482707293882[145] = 0.0;
   out_7308623482707293882[146] = 0.0;
   out_7308623482707293882[147] = 0.0;
   out_7308623482707293882[148] = 0.0;
   out_7308623482707293882[149] = 0.0;
   out_7308623482707293882[150] = 0.0;
   out_7308623482707293882[151] = 0.0;
   out_7308623482707293882[152] = 1.0;
   out_7308623482707293882[153] = 0.0;
   out_7308623482707293882[154] = 0.0;
   out_7308623482707293882[155] = 0.0;
   out_7308623482707293882[156] = 0.0;
   out_7308623482707293882[157] = 0.0;
   out_7308623482707293882[158] = 0.0;
   out_7308623482707293882[159] = 0.0;
   out_7308623482707293882[160] = 0.0;
   out_7308623482707293882[161] = 0.0;
   out_7308623482707293882[162] = 0.0;
   out_7308623482707293882[163] = 0.0;
   out_7308623482707293882[164] = 0.0;
   out_7308623482707293882[165] = 0.0;
   out_7308623482707293882[166] = 0.0;
   out_7308623482707293882[167] = 0.0;
   out_7308623482707293882[168] = 0.0;
   out_7308623482707293882[169] = 0.0;
   out_7308623482707293882[170] = 0.0;
   out_7308623482707293882[171] = 1.0;
   out_7308623482707293882[172] = 0.0;
   out_7308623482707293882[173] = 0.0;
   out_7308623482707293882[174] = 0.0;
   out_7308623482707293882[175] = 0.0;
   out_7308623482707293882[176] = 0.0;
   out_7308623482707293882[177] = 0.0;
   out_7308623482707293882[178] = 0.0;
   out_7308623482707293882[179] = 0.0;
   out_7308623482707293882[180] = 0.0;
   out_7308623482707293882[181] = 0.0;
   out_7308623482707293882[182] = 0.0;
   out_7308623482707293882[183] = 0.0;
   out_7308623482707293882[184] = 0.0;
   out_7308623482707293882[185] = 0.0;
   out_7308623482707293882[186] = 0.0;
   out_7308623482707293882[187] = 0.0;
   out_7308623482707293882[188] = 0.0;
   out_7308623482707293882[189] = 0.0;
   out_7308623482707293882[190] = 1.0;
   out_7308623482707293882[191] = 0.0;
   out_7308623482707293882[192] = 0.0;
   out_7308623482707293882[193] = 0.0;
   out_7308623482707293882[194] = 0.0;
   out_7308623482707293882[195] = 0.0;
   out_7308623482707293882[196] = 0.0;
   out_7308623482707293882[197] = 0.0;
   out_7308623482707293882[198] = 0.0;
   out_7308623482707293882[199] = 0.0;
   out_7308623482707293882[200] = 0.0;
   out_7308623482707293882[201] = 0.0;
   out_7308623482707293882[202] = 0.0;
   out_7308623482707293882[203] = 0.0;
   out_7308623482707293882[204] = 0.0;
   out_7308623482707293882[205] = 0.0;
   out_7308623482707293882[206] = 0.0;
   out_7308623482707293882[207] = 0.0;
   out_7308623482707293882[208] = 0.0;
   out_7308623482707293882[209] = 1.0;
   out_7308623482707293882[210] = 0.0;
   out_7308623482707293882[211] = 0.0;
   out_7308623482707293882[212] = 0.0;
   out_7308623482707293882[213] = 0.0;
   out_7308623482707293882[214] = 0.0;
   out_7308623482707293882[215] = 0.0;
   out_7308623482707293882[216] = 0.0;
   out_7308623482707293882[217] = 0.0;
   out_7308623482707293882[218] = 0.0;
   out_7308623482707293882[219] = 0.0;
   out_7308623482707293882[220] = 0.0;
   out_7308623482707293882[221] = 0.0;
   out_7308623482707293882[222] = 0.0;
   out_7308623482707293882[223] = 0.0;
   out_7308623482707293882[224] = 0.0;
   out_7308623482707293882[225] = 0.0;
   out_7308623482707293882[226] = 0.0;
   out_7308623482707293882[227] = 0.0;
   out_7308623482707293882[228] = 1.0;
   out_7308623482707293882[229] = 0.0;
   out_7308623482707293882[230] = 0.0;
   out_7308623482707293882[231] = 0.0;
   out_7308623482707293882[232] = 0.0;
   out_7308623482707293882[233] = 0.0;
   out_7308623482707293882[234] = 0.0;
   out_7308623482707293882[235] = 0.0;
   out_7308623482707293882[236] = 0.0;
   out_7308623482707293882[237] = 0.0;
   out_7308623482707293882[238] = 0.0;
   out_7308623482707293882[239] = 0.0;
   out_7308623482707293882[240] = 0.0;
   out_7308623482707293882[241] = 0.0;
   out_7308623482707293882[242] = 0.0;
   out_7308623482707293882[243] = 0.0;
   out_7308623482707293882[244] = 0.0;
   out_7308623482707293882[245] = 0.0;
   out_7308623482707293882[246] = 0.0;
   out_7308623482707293882[247] = 1.0;
   out_7308623482707293882[248] = 0.0;
   out_7308623482707293882[249] = 0.0;
   out_7308623482707293882[250] = 0.0;
   out_7308623482707293882[251] = 0.0;
   out_7308623482707293882[252] = 0.0;
   out_7308623482707293882[253] = 0.0;
   out_7308623482707293882[254] = 0.0;
   out_7308623482707293882[255] = 0.0;
   out_7308623482707293882[256] = 0.0;
   out_7308623482707293882[257] = 0.0;
   out_7308623482707293882[258] = 0.0;
   out_7308623482707293882[259] = 0.0;
   out_7308623482707293882[260] = 0.0;
   out_7308623482707293882[261] = 0.0;
   out_7308623482707293882[262] = 0.0;
   out_7308623482707293882[263] = 0.0;
   out_7308623482707293882[264] = 0.0;
   out_7308623482707293882[265] = 0.0;
   out_7308623482707293882[266] = 1.0;
   out_7308623482707293882[267] = 0.0;
   out_7308623482707293882[268] = 0.0;
   out_7308623482707293882[269] = 0.0;
   out_7308623482707293882[270] = 0.0;
   out_7308623482707293882[271] = 0.0;
   out_7308623482707293882[272] = 0.0;
   out_7308623482707293882[273] = 0.0;
   out_7308623482707293882[274] = 0.0;
   out_7308623482707293882[275] = 0.0;
   out_7308623482707293882[276] = 0.0;
   out_7308623482707293882[277] = 0.0;
   out_7308623482707293882[278] = 0.0;
   out_7308623482707293882[279] = 0.0;
   out_7308623482707293882[280] = 0.0;
   out_7308623482707293882[281] = 0.0;
   out_7308623482707293882[282] = 0.0;
   out_7308623482707293882[283] = 0.0;
   out_7308623482707293882[284] = 0.0;
   out_7308623482707293882[285] = 1.0;
   out_7308623482707293882[286] = 0.0;
   out_7308623482707293882[287] = 0.0;
   out_7308623482707293882[288] = 0.0;
   out_7308623482707293882[289] = 0.0;
   out_7308623482707293882[290] = 0.0;
   out_7308623482707293882[291] = 0.0;
   out_7308623482707293882[292] = 0.0;
   out_7308623482707293882[293] = 0.0;
   out_7308623482707293882[294] = 0.0;
   out_7308623482707293882[295] = 0.0;
   out_7308623482707293882[296] = 0.0;
   out_7308623482707293882[297] = 0.0;
   out_7308623482707293882[298] = 0.0;
   out_7308623482707293882[299] = 0.0;
   out_7308623482707293882[300] = 0.0;
   out_7308623482707293882[301] = 0.0;
   out_7308623482707293882[302] = 0.0;
   out_7308623482707293882[303] = 0.0;
   out_7308623482707293882[304] = 1.0;
   out_7308623482707293882[305] = 0.0;
   out_7308623482707293882[306] = 0.0;
   out_7308623482707293882[307] = 0.0;
   out_7308623482707293882[308] = 0.0;
   out_7308623482707293882[309] = 0.0;
   out_7308623482707293882[310] = 0.0;
   out_7308623482707293882[311] = 0.0;
   out_7308623482707293882[312] = 0.0;
   out_7308623482707293882[313] = 0.0;
   out_7308623482707293882[314] = 0.0;
   out_7308623482707293882[315] = 0.0;
   out_7308623482707293882[316] = 0.0;
   out_7308623482707293882[317] = 0.0;
   out_7308623482707293882[318] = 0.0;
   out_7308623482707293882[319] = 0.0;
   out_7308623482707293882[320] = 0.0;
   out_7308623482707293882[321] = 0.0;
   out_7308623482707293882[322] = 0.0;
   out_7308623482707293882[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1494187582519062096) {
   out_1494187582519062096[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1494187582519062096[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1494187582519062096[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1494187582519062096[3] = dt*state[12] + state[3];
   out_1494187582519062096[4] = dt*state[13] + state[4];
   out_1494187582519062096[5] = dt*state[14] + state[5];
   out_1494187582519062096[6] = state[6];
   out_1494187582519062096[7] = state[7];
   out_1494187582519062096[8] = state[8];
   out_1494187582519062096[9] = state[9];
   out_1494187582519062096[10] = state[10];
   out_1494187582519062096[11] = state[11];
   out_1494187582519062096[12] = state[12];
   out_1494187582519062096[13] = state[13];
   out_1494187582519062096[14] = state[14];
   out_1494187582519062096[15] = state[15];
   out_1494187582519062096[16] = state[16];
   out_1494187582519062096[17] = state[17];
}
void F_fun(double *state, double dt, double *out_440712768552739407) {
   out_440712768552739407[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_440712768552739407[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_440712768552739407[2] = 0;
   out_440712768552739407[3] = 0;
   out_440712768552739407[4] = 0;
   out_440712768552739407[5] = 0;
   out_440712768552739407[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_440712768552739407[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_440712768552739407[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_440712768552739407[9] = 0;
   out_440712768552739407[10] = 0;
   out_440712768552739407[11] = 0;
   out_440712768552739407[12] = 0;
   out_440712768552739407[13] = 0;
   out_440712768552739407[14] = 0;
   out_440712768552739407[15] = 0;
   out_440712768552739407[16] = 0;
   out_440712768552739407[17] = 0;
   out_440712768552739407[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_440712768552739407[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_440712768552739407[20] = 0;
   out_440712768552739407[21] = 0;
   out_440712768552739407[22] = 0;
   out_440712768552739407[23] = 0;
   out_440712768552739407[24] = 0;
   out_440712768552739407[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_440712768552739407[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_440712768552739407[27] = 0;
   out_440712768552739407[28] = 0;
   out_440712768552739407[29] = 0;
   out_440712768552739407[30] = 0;
   out_440712768552739407[31] = 0;
   out_440712768552739407[32] = 0;
   out_440712768552739407[33] = 0;
   out_440712768552739407[34] = 0;
   out_440712768552739407[35] = 0;
   out_440712768552739407[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_440712768552739407[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_440712768552739407[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_440712768552739407[39] = 0;
   out_440712768552739407[40] = 0;
   out_440712768552739407[41] = 0;
   out_440712768552739407[42] = 0;
   out_440712768552739407[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_440712768552739407[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_440712768552739407[45] = 0;
   out_440712768552739407[46] = 0;
   out_440712768552739407[47] = 0;
   out_440712768552739407[48] = 0;
   out_440712768552739407[49] = 0;
   out_440712768552739407[50] = 0;
   out_440712768552739407[51] = 0;
   out_440712768552739407[52] = 0;
   out_440712768552739407[53] = 0;
   out_440712768552739407[54] = 0;
   out_440712768552739407[55] = 0;
   out_440712768552739407[56] = 0;
   out_440712768552739407[57] = 1;
   out_440712768552739407[58] = 0;
   out_440712768552739407[59] = 0;
   out_440712768552739407[60] = 0;
   out_440712768552739407[61] = 0;
   out_440712768552739407[62] = 0;
   out_440712768552739407[63] = 0;
   out_440712768552739407[64] = 0;
   out_440712768552739407[65] = 0;
   out_440712768552739407[66] = dt;
   out_440712768552739407[67] = 0;
   out_440712768552739407[68] = 0;
   out_440712768552739407[69] = 0;
   out_440712768552739407[70] = 0;
   out_440712768552739407[71] = 0;
   out_440712768552739407[72] = 0;
   out_440712768552739407[73] = 0;
   out_440712768552739407[74] = 0;
   out_440712768552739407[75] = 0;
   out_440712768552739407[76] = 1;
   out_440712768552739407[77] = 0;
   out_440712768552739407[78] = 0;
   out_440712768552739407[79] = 0;
   out_440712768552739407[80] = 0;
   out_440712768552739407[81] = 0;
   out_440712768552739407[82] = 0;
   out_440712768552739407[83] = 0;
   out_440712768552739407[84] = 0;
   out_440712768552739407[85] = dt;
   out_440712768552739407[86] = 0;
   out_440712768552739407[87] = 0;
   out_440712768552739407[88] = 0;
   out_440712768552739407[89] = 0;
   out_440712768552739407[90] = 0;
   out_440712768552739407[91] = 0;
   out_440712768552739407[92] = 0;
   out_440712768552739407[93] = 0;
   out_440712768552739407[94] = 0;
   out_440712768552739407[95] = 1;
   out_440712768552739407[96] = 0;
   out_440712768552739407[97] = 0;
   out_440712768552739407[98] = 0;
   out_440712768552739407[99] = 0;
   out_440712768552739407[100] = 0;
   out_440712768552739407[101] = 0;
   out_440712768552739407[102] = 0;
   out_440712768552739407[103] = 0;
   out_440712768552739407[104] = dt;
   out_440712768552739407[105] = 0;
   out_440712768552739407[106] = 0;
   out_440712768552739407[107] = 0;
   out_440712768552739407[108] = 0;
   out_440712768552739407[109] = 0;
   out_440712768552739407[110] = 0;
   out_440712768552739407[111] = 0;
   out_440712768552739407[112] = 0;
   out_440712768552739407[113] = 0;
   out_440712768552739407[114] = 1;
   out_440712768552739407[115] = 0;
   out_440712768552739407[116] = 0;
   out_440712768552739407[117] = 0;
   out_440712768552739407[118] = 0;
   out_440712768552739407[119] = 0;
   out_440712768552739407[120] = 0;
   out_440712768552739407[121] = 0;
   out_440712768552739407[122] = 0;
   out_440712768552739407[123] = 0;
   out_440712768552739407[124] = 0;
   out_440712768552739407[125] = 0;
   out_440712768552739407[126] = 0;
   out_440712768552739407[127] = 0;
   out_440712768552739407[128] = 0;
   out_440712768552739407[129] = 0;
   out_440712768552739407[130] = 0;
   out_440712768552739407[131] = 0;
   out_440712768552739407[132] = 0;
   out_440712768552739407[133] = 1;
   out_440712768552739407[134] = 0;
   out_440712768552739407[135] = 0;
   out_440712768552739407[136] = 0;
   out_440712768552739407[137] = 0;
   out_440712768552739407[138] = 0;
   out_440712768552739407[139] = 0;
   out_440712768552739407[140] = 0;
   out_440712768552739407[141] = 0;
   out_440712768552739407[142] = 0;
   out_440712768552739407[143] = 0;
   out_440712768552739407[144] = 0;
   out_440712768552739407[145] = 0;
   out_440712768552739407[146] = 0;
   out_440712768552739407[147] = 0;
   out_440712768552739407[148] = 0;
   out_440712768552739407[149] = 0;
   out_440712768552739407[150] = 0;
   out_440712768552739407[151] = 0;
   out_440712768552739407[152] = 1;
   out_440712768552739407[153] = 0;
   out_440712768552739407[154] = 0;
   out_440712768552739407[155] = 0;
   out_440712768552739407[156] = 0;
   out_440712768552739407[157] = 0;
   out_440712768552739407[158] = 0;
   out_440712768552739407[159] = 0;
   out_440712768552739407[160] = 0;
   out_440712768552739407[161] = 0;
   out_440712768552739407[162] = 0;
   out_440712768552739407[163] = 0;
   out_440712768552739407[164] = 0;
   out_440712768552739407[165] = 0;
   out_440712768552739407[166] = 0;
   out_440712768552739407[167] = 0;
   out_440712768552739407[168] = 0;
   out_440712768552739407[169] = 0;
   out_440712768552739407[170] = 0;
   out_440712768552739407[171] = 1;
   out_440712768552739407[172] = 0;
   out_440712768552739407[173] = 0;
   out_440712768552739407[174] = 0;
   out_440712768552739407[175] = 0;
   out_440712768552739407[176] = 0;
   out_440712768552739407[177] = 0;
   out_440712768552739407[178] = 0;
   out_440712768552739407[179] = 0;
   out_440712768552739407[180] = 0;
   out_440712768552739407[181] = 0;
   out_440712768552739407[182] = 0;
   out_440712768552739407[183] = 0;
   out_440712768552739407[184] = 0;
   out_440712768552739407[185] = 0;
   out_440712768552739407[186] = 0;
   out_440712768552739407[187] = 0;
   out_440712768552739407[188] = 0;
   out_440712768552739407[189] = 0;
   out_440712768552739407[190] = 1;
   out_440712768552739407[191] = 0;
   out_440712768552739407[192] = 0;
   out_440712768552739407[193] = 0;
   out_440712768552739407[194] = 0;
   out_440712768552739407[195] = 0;
   out_440712768552739407[196] = 0;
   out_440712768552739407[197] = 0;
   out_440712768552739407[198] = 0;
   out_440712768552739407[199] = 0;
   out_440712768552739407[200] = 0;
   out_440712768552739407[201] = 0;
   out_440712768552739407[202] = 0;
   out_440712768552739407[203] = 0;
   out_440712768552739407[204] = 0;
   out_440712768552739407[205] = 0;
   out_440712768552739407[206] = 0;
   out_440712768552739407[207] = 0;
   out_440712768552739407[208] = 0;
   out_440712768552739407[209] = 1;
   out_440712768552739407[210] = 0;
   out_440712768552739407[211] = 0;
   out_440712768552739407[212] = 0;
   out_440712768552739407[213] = 0;
   out_440712768552739407[214] = 0;
   out_440712768552739407[215] = 0;
   out_440712768552739407[216] = 0;
   out_440712768552739407[217] = 0;
   out_440712768552739407[218] = 0;
   out_440712768552739407[219] = 0;
   out_440712768552739407[220] = 0;
   out_440712768552739407[221] = 0;
   out_440712768552739407[222] = 0;
   out_440712768552739407[223] = 0;
   out_440712768552739407[224] = 0;
   out_440712768552739407[225] = 0;
   out_440712768552739407[226] = 0;
   out_440712768552739407[227] = 0;
   out_440712768552739407[228] = 1;
   out_440712768552739407[229] = 0;
   out_440712768552739407[230] = 0;
   out_440712768552739407[231] = 0;
   out_440712768552739407[232] = 0;
   out_440712768552739407[233] = 0;
   out_440712768552739407[234] = 0;
   out_440712768552739407[235] = 0;
   out_440712768552739407[236] = 0;
   out_440712768552739407[237] = 0;
   out_440712768552739407[238] = 0;
   out_440712768552739407[239] = 0;
   out_440712768552739407[240] = 0;
   out_440712768552739407[241] = 0;
   out_440712768552739407[242] = 0;
   out_440712768552739407[243] = 0;
   out_440712768552739407[244] = 0;
   out_440712768552739407[245] = 0;
   out_440712768552739407[246] = 0;
   out_440712768552739407[247] = 1;
   out_440712768552739407[248] = 0;
   out_440712768552739407[249] = 0;
   out_440712768552739407[250] = 0;
   out_440712768552739407[251] = 0;
   out_440712768552739407[252] = 0;
   out_440712768552739407[253] = 0;
   out_440712768552739407[254] = 0;
   out_440712768552739407[255] = 0;
   out_440712768552739407[256] = 0;
   out_440712768552739407[257] = 0;
   out_440712768552739407[258] = 0;
   out_440712768552739407[259] = 0;
   out_440712768552739407[260] = 0;
   out_440712768552739407[261] = 0;
   out_440712768552739407[262] = 0;
   out_440712768552739407[263] = 0;
   out_440712768552739407[264] = 0;
   out_440712768552739407[265] = 0;
   out_440712768552739407[266] = 1;
   out_440712768552739407[267] = 0;
   out_440712768552739407[268] = 0;
   out_440712768552739407[269] = 0;
   out_440712768552739407[270] = 0;
   out_440712768552739407[271] = 0;
   out_440712768552739407[272] = 0;
   out_440712768552739407[273] = 0;
   out_440712768552739407[274] = 0;
   out_440712768552739407[275] = 0;
   out_440712768552739407[276] = 0;
   out_440712768552739407[277] = 0;
   out_440712768552739407[278] = 0;
   out_440712768552739407[279] = 0;
   out_440712768552739407[280] = 0;
   out_440712768552739407[281] = 0;
   out_440712768552739407[282] = 0;
   out_440712768552739407[283] = 0;
   out_440712768552739407[284] = 0;
   out_440712768552739407[285] = 1;
   out_440712768552739407[286] = 0;
   out_440712768552739407[287] = 0;
   out_440712768552739407[288] = 0;
   out_440712768552739407[289] = 0;
   out_440712768552739407[290] = 0;
   out_440712768552739407[291] = 0;
   out_440712768552739407[292] = 0;
   out_440712768552739407[293] = 0;
   out_440712768552739407[294] = 0;
   out_440712768552739407[295] = 0;
   out_440712768552739407[296] = 0;
   out_440712768552739407[297] = 0;
   out_440712768552739407[298] = 0;
   out_440712768552739407[299] = 0;
   out_440712768552739407[300] = 0;
   out_440712768552739407[301] = 0;
   out_440712768552739407[302] = 0;
   out_440712768552739407[303] = 0;
   out_440712768552739407[304] = 1;
   out_440712768552739407[305] = 0;
   out_440712768552739407[306] = 0;
   out_440712768552739407[307] = 0;
   out_440712768552739407[308] = 0;
   out_440712768552739407[309] = 0;
   out_440712768552739407[310] = 0;
   out_440712768552739407[311] = 0;
   out_440712768552739407[312] = 0;
   out_440712768552739407[313] = 0;
   out_440712768552739407[314] = 0;
   out_440712768552739407[315] = 0;
   out_440712768552739407[316] = 0;
   out_440712768552739407[317] = 0;
   out_440712768552739407[318] = 0;
   out_440712768552739407[319] = 0;
   out_440712768552739407[320] = 0;
   out_440712768552739407[321] = 0;
   out_440712768552739407[322] = 0;
   out_440712768552739407[323] = 1;
}
void h_4(double *state, double *unused, double *out_3074332647112967580) {
   out_3074332647112967580[0] = state[6] + state[9];
   out_3074332647112967580[1] = state[7] + state[10];
   out_3074332647112967580[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5985602205963176999) {
   out_5985602205963176999[0] = 0;
   out_5985602205963176999[1] = 0;
   out_5985602205963176999[2] = 0;
   out_5985602205963176999[3] = 0;
   out_5985602205963176999[4] = 0;
   out_5985602205963176999[5] = 0;
   out_5985602205963176999[6] = 1;
   out_5985602205963176999[7] = 0;
   out_5985602205963176999[8] = 0;
   out_5985602205963176999[9] = 1;
   out_5985602205963176999[10] = 0;
   out_5985602205963176999[11] = 0;
   out_5985602205963176999[12] = 0;
   out_5985602205963176999[13] = 0;
   out_5985602205963176999[14] = 0;
   out_5985602205963176999[15] = 0;
   out_5985602205963176999[16] = 0;
   out_5985602205963176999[17] = 0;
   out_5985602205963176999[18] = 0;
   out_5985602205963176999[19] = 0;
   out_5985602205963176999[20] = 0;
   out_5985602205963176999[21] = 0;
   out_5985602205963176999[22] = 0;
   out_5985602205963176999[23] = 0;
   out_5985602205963176999[24] = 0;
   out_5985602205963176999[25] = 1;
   out_5985602205963176999[26] = 0;
   out_5985602205963176999[27] = 0;
   out_5985602205963176999[28] = 1;
   out_5985602205963176999[29] = 0;
   out_5985602205963176999[30] = 0;
   out_5985602205963176999[31] = 0;
   out_5985602205963176999[32] = 0;
   out_5985602205963176999[33] = 0;
   out_5985602205963176999[34] = 0;
   out_5985602205963176999[35] = 0;
   out_5985602205963176999[36] = 0;
   out_5985602205963176999[37] = 0;
   out_5985602205963176999[38] = 0;
   out_5985602205963176999[39] = 0;
   out_5985602205963176999[40] = 0;
   out_5985602205963176999[41] = 0;
   out_5985602205963176999[42] = 0;
   out_5985602205963176999[43] = 0;
   out_5985602205963176999[44] = 1;
   out_5985602205963176999[45] = 0;
   out_5985602205963176999[46] = 0;
   out_5985602205963176999[47] = 1;
   out_5985602205963176999[48] = 0;
   out_5985602205963176999[49] = 0;
   out_5985602205963176999[50] = 0;
   out_5985602205963176999[51] = 0;
   out_5985602205963176999[52] = 0;
   out_5985602205963176999[53] = 0;
}
void h_10(double *state, double *unused, double *out_8586129477608731499) {
   out_8586129477608731499[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8586129477608731499[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8586129477608731499[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_7002946320442292) {
   out_7002946320442292[0] = 0;
   out_7002946320442292[1] = 9.8100000000000005*cos(state[1]);
   out_7002946320442292[2] = 0;
   out_7002946320442292[3] = 0;
   out_7002946320442292[4] = -state[8];
   out_7002946320442292[5] = state[7];
   out_7002946320442292[6] = 0;
   out_7002946320442292[7] = state[5];
   out_7002946320442292[8] = -state[4];
   out_7002946320442292[9] = 0;
   out_7002946320442292[10] = 0;
   out_7002946320442292[11] = 0;
   out_7002946320442292[12] = 1;
   out_7002946320442292[13] = 0;
   out_7002946320442292[14] = 0;
   out_7002946320442292[15] = 1;
   out_7002946320442292[16] = 0;
   out_7002946320442292[17] = 0;
   out_7002946320442292[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_7002946320442292[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_7002946320442292[20] = 0;
   out_7002946320442292[21] = state[8];
   out_7002946320442292[22] = 0;
   out_7002946320442292[23] = -state[6];
   out_7002946320442292[24] = -state[5];
   out_7002946320442292[25] = 0;
   out_7002946320442292[26] = state[3];
   out_7002946320442292[27] = 0;
   out_7002946320442292[28] = 0;
   out_7002946320442292[29] = 0;
   out_7002946320442292[30] = 0;
   out_7002946320442292[31] = 1;
   out_7002946320442292[32] = 0;
   out_7002946320442292[33] = 0;
   out_7002946320442292[34] = 1;
   out_7002946320442292[35] = 0;
   out_7002946320442292[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_7002946320442292[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_7002946320442292[38] = 0;
   out_7002946320442292[39] = -state[7];
   out_7002946320442292[40] = state[6];
   out_7002946320442292[41] = 0;
   out_7002946320442292[42] = state[4];
   out_7002946320442292[43] = -state[3];
   out_7002946320442292[44] = 0;
   out_7002946320442292[45] = 0;
   out_7002946320442292[46] = 0;
   out_7002946320442292[47] = 0;
   out_7002946320442292[48] = 0;
   out_7002946320442292[49] = 0;
   out_7002946320442292[50] = 1;
   out_7002946320442292[51] = 0;
   out_7002946320442292[52] = 0;
   out_7002946320442292[53] = 1;
}
void h_13(double *state, double *unused, double *out_7994066762082839895) {
   out_7994066762082839895[0] = state[3];
   out_7994066762082839895[1] = state[4];
   out_7994066762082839895[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2773328380630844198) {
   out_2773328380630844198[0] = 0;
   out_2773328380630844198[1] = 0;
   out_2773328380630844198[2] = 0;
   out_2773328380630844198[3] = 1;
   out_2773328380630844198[4] = 0;
   out_2773328380630844198[5] = 0;
   out_2773328380630844198[6] = 0;
   out_2773328380630844198[7] = 0;
   out_2773328380630844198[8] = 0;
   out_2773328380630844198[9] = 0;
   out_2773328380630844198[10] = 0;
   out_2773328380630844198[11] = 0;
   out_2773328380630844198[12] = 0;
   out_2773328380630844198[13] = 0;
   out_2773328380630844198[14] = 0;
   out_2773328380630844198[15] = 0;
   out_2773328380630844198[16] = 0;
   out_2773328380630844198[17] = 0;
   out_2773328380630844198[18] = 0;
   out_2773328380630844198[19] = 0;
   out_2773328380630844198[20] = 0;
   out_2773328380630844198[21] = 0;
   out_2773328380630844198[22] = 1;
   out_2773328380630844198[23] = 0;
   out_2773328380630844198[24] = 0;
   out_2773328380630844198[25] = 0;
   out_2773328380630844198[26] = 0;
   out_2773328380630844198[27] = 0;
   out_2773328380630844198[28] = 0;
   out_2773328380630844198[29] = 0;
   out_2773328380630844198[30] = 0;
   out_2773328380630844198[31] = 0;
   out_2773328380630844198[32] = 0;
   out_2773328380630844198[33] = 0;
   out_2773328380630844198[34] = 0;
   out_2773328380630844198[35] = 0;
   out_2773328380630844198[36] = 0;
   out_2773328380630844198[37] = 0;
   out_2773328380630844198[38] = 0;
   out_2773328380630844198[39] = 0;
   out_2773328380630844198[40] = 0;
   out_2773328380630844198[41] = 1;
   out_2773328380630844198[42] = 0;
   out_2773328380630844198[43] = 0;
   out_2773328380630844198[44] = 0;
   out_2773328380630844198[45] = 0;
   out_2773328380630844198[46] = 0;
   out_2773328380630844198[47] = 0;
   out_2773328380630844198[48] = 0;
   out_2773328380630844198[49] = 0;
   out_2773328380630844198[50] = 0;
   out_2773328380630844198[51] = 0;
   out_2773328380630844198[52] = 0;
   out_2773328380630844198[53] = 0;
}
void h_14(double *state, double *unused, double *out_2538869907344583488) {
   out_2538869907344583488[0] = state[6];
   out_2538869907344583488[1] = state[7];
   out_2538869907344583488[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2022361349623692470) {
   out_2022361349623692470[0] = 0;
   out_2022361349623692470[1] = 0;
   out_2022361349623692470[2] = 0;
   out_2022361349623692470[3] = 0;
   out_2022361349623692470[4] = 0;
   out_2022361349623692470[5] = 0;
   out_2022361349623692470[6] = 1;
   out_2022361349623692470[7] = 0;
   out_2022361349623692470[8] = 0;
   out_2022361349623692470[9] = 0;
   out_2022361349623692470[10] = 0;
   out_2022361349623692470[11] = 0;
   out_2022361349623692470[12] = 0;
   out_2022361349623692470[13] = 0;
   out_2022361349623692470[14] = 0;
   out_2022361349623692470[15] = 0;
   out_2022361349623692470[16] = 0;
   out_2022361349623692470[17] = 0;
   out_2022361349623692470[18] = 0;
   out_2022361349623692470[19] = 0;
   out_2022361349623692470[20] = 0;
   out_2022361349623692470[21] = 0;
   out_2022361349623692470[22] = 0;
   out_2022361349623692470[23] = 0;
   out_2022361349623692470[24] = 0;
   out_2022361349623692470[25] = 1;
   out_2022361349623692470[26] = 0;
   out_2022361349623692470[27] = 0;
   out_2022361349623692470[28] = 0;
   out_2022361349623692470[29] = 0;
   out_2022361349623692470[30] = 0;
   out_2022361349623692470[31] = 0;
   out_2022361349623692470[32] = 0;
   out_2022361349623692470[33] = 0;
   out_2022361349623692470[34] = 0;
   out_2022361349623692470[35] = 0;
   out_2022361349623692470[36] = 0;
   out_2022361349623692470[37] = 0;
   out_2022361349623692470[38] = 0;
   out_2022361349623692470[39] = 0;
   out_2022361349623692470[40] = 0;
   out_2022361349623692470[41] = 0;
   out_2022361349623692470[42] = 0;
   out_2022361349623692470[43] = 0;
   out_2022361349623692470[44] = 1;
   out_2022361349623692470[45] = 0;
   out_2022361349623692470[46] = 0;
   out_2022361349623692470[47] = 0;
   out_2022361349623692470[48] = 0;
   out_2022361349623692470[49] = 0;
   out_2022361349623692470[50] = 0;
   out_2022361349623692470[51] = 0;
   out_2022361349623692470[52] = 0;
   out_2022361349623692470[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_287223720192222431) {
  err_fun(nom_x, delta_x, out_287223720192222431);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7604442797155520121) {
  inv_err_fun(nom_x, true_x, out_7604442797155520121);
}
void pose_H_mod_fun(double *state, double *out_7308623482707293882) {
  H_mod_fun(state, out_7308623482707293882);
}
void pose_f_fun(double *state, double dt, double *out_1494187582519062096) {
  f_fun(state,  dt, out_1494187582519062096);
}
void pose_F_fun(double *state, double dt, double *out_440712768552739407) {
  F_fun(state,  dt, out_440712768552739407);
}
void pose_h_4(double *state, double *unused, double *out_3074332647112967580) {
  h_4(state, unused, out_3074332647112967580);
}
void pose_H_4(double *state, double *unused, double *out_5985602205963176999) {
  H_4(state, unused, out_5985602205963176999);
}
void pose_h_10(double *state, double *unused, double *out_8586129477608731499) {
  h_10(state, unused, out_8586129477608731499);
}
void pose_H_10(double *state, double *unused, double *out_7002946320442292) {
  H_10(state, unused, out_7002946320442292);
}
void pose_h_13(double *state, double *unused, double *out_7994066762082839895) {
  h_13(state, unused, out_7994066762082839895);
}
void pose_H_13(double *state, double *unused, double *out_2773328380630844198) {
  H_13(state, unused, out_2773328380630844198);
}
void pose_h_14(double *state, double *unused, double *out_2538869907344583488) {
  h_14(state, unused, out_2538869907344583488);
}
void pose_H_14(double *state, double *unused, double *out_2022361349623692470) {
  H_14(state, unused, out_2022361349623692470);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
