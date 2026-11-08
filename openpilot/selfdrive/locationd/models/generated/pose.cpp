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
void err_fun(double *nom_x, double *delta_x, double *out_8222070877202252563) {
   out_8222070877202252563[0] = delta_x[0] + nom_x[0];
   out_8222070877202252563[1] = delta_x[1] + nom_x[1];
   out_8222070877202252563[2] = delta_x[2] + nom_x[2];
   out_8222070877202252563[3] = delta_x[3] + nom_x[3];
   out_8222070877202252563[4] = delta_x[4] + nom_x[4];
   out_8222070877202252563[5] = delta_x[5] + nom_x[5];
   out_8222070877202252563[6] = delta_x[6] + nom_x[6];
   out_8222070877202252563[7] = delta_x[7] + nom_x[7];
   out_8222070877202252563[8] = delta_x[8] + nom_x[8];
   out_8222070877202252563[9] = delta_x[9] + nom_x[9];
   out_8222070877202252563[10] = delta_x[10] + nom_x[10];
   out_8222070877202252563[11] = delta_x[11] + nom_x[11];
   out_8222070877202252563[12] = delta_x[12] + nom_x[12];
   out_8222070877202252563[13] = delta_x[13] + nom_x[13];
   out_8222070877202252563[14] = delta_x[14] + nom_x[14];
   out_8222070877202252563[15] = delta_x[15] + nom_x[15];
   out_8222070877202252563[16] = delta_x[16] + nom_x[16];
   out_8222070877202252563[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7433102429512158712) {
   out_7433102429512158712[0] = -nom_x[0] + true_x[0];
   out_7433102429512158712[1] = -nom_x[1] + true_x[1];
   out_7433102429512158712[2] = -nom_x[2] + true_x[2];
   out_7433102429512158712[3] = -nom_x[3] + true_x[3];
   out_7433102429512158712[4] = -nom_x[4] + true_x[4];
   out_7433102429512158712[5] = -nom_x[5] + true_x[5];
   out_7433102429512158712[6] = -nom_x[6] + true_x[6];
   out_7433102429512158712[7] = -nom_x[7] + true_x[7];
   out_7433102429512158712[8] = -nom_x[8] + true_x[8];
   out_7433102429512158712[9] = -nom_x[9] + true_x[9];
   out_7433102429512158712[10] = -nom_x[10] + true_x[10];
   out_7433102429512158712[11] = -nom_x[11] + true_x[11];
   out_7433102429512158712[12] = -nom_x[12] + true_x[12];
   out_7433102429512158712[13] = -nom_x[13] + true_x[13];
   out_7433102429512158712[14] = -nom_x[14] + true_x[14];
   out_7433102429512158712[15] = -nom_x[15] + true_x[15];
   out_7433102429512158712[16] = -nom_x[16] + true_x[16];
   out_7433102429512158712[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4199070111182038978) {
   out_4199070111182038978[0] = 1.0;
   out_4199070111182038978[1] = 0.0;
   out_4199070111182038978[2] = 0.0;
   out_4199070111182038978[3] = 0.0;
   out_4199070111182038978[4] = 0.0;
   out_4199070111182038978[5] = 0.0;
   out_4199070111182038978[6] = 0.0;
   out_4199070111182038978[7] = 0.0;
   out_4199070111182038978[8] = 0.0;
   out_4199070111182038978[9] = 0.0;
   out_4199070111182038978[10] = 0.0;
   out_4199070111182038978[11] = 0.0;
   out_4199070111182038978[12] = 0.0;
   out_4199070111182038978[13] = 0.0;
   out_4199070111182038978[14] = 0.0;
   out_4199070111182038978[15] = 0.0;
   out_4199070111182038978[16] = 0.0;
   out_4199070111182038978[17] = 0.0;
   out_4199070111182038978[18] = 0.0;
   out_4199070111182038978[19] = 1.0;
   out_4199070111182038978[20] = 0.0;
   out_4199070111182038978[21] = 0.0;
   out_4199070111182038978[22] = 0.0;
   out_4199070111182038978[23] = 0.0;
   out_4199070111182038978[24] = 0.0;
   out_4199070111182038978[25] = 0.0;
   out_4199070111182038978[26] = 0.0;
   out_4199070111182038978[27] = 0.0;
   out_4199070111182038978[28] = 0.0;
   out_4199070111182038978[29] = 0.0;
   out_4199070111182038978[30] = 0.0;
   out_4199070111182038978[31] = 0.0;
   out_4199070111182038978[32] = 0.0;
   out_4199070111182038978[33] = 0.0;
   out_4199070111182038978[34] = 0.0;
   out_4199070111182038978[35] = 0.0;
   out_4199070111182038978[36] = 0.0;
   out_4199070111182038978[37] = 0.0;
   out_4199070111182038978[38] = 1.0;
   out_4199070111182038978[39] = 0.0;
   out_4199070111182038978[40] = 0.0;
   out_4199070111182038978[41] = 0.0;
   out_4199070111182038978[42] = 0.0;
   out_4199070111182038978[43] = 0.0;
   out_4199070111182038978[44] = 0.0;
   out_4199070111182038978[45] = 0.0;
   out_4199070111182038978[46] = 0.0;
   out_4199070111182038978[47] = 0.0;
   out_4199070111182038978[48] = 0.0;
   out_4199070111182038978[49] = 0.0;
   out_4199070111182038978[50] = 0.0;
   out_4199070111182038978[51] = 0.0;
   out_4199070111182038978[52] = 0.0;
   out_4199070111182038978[53] = 0.0;
   out_4199070111182038978[54] = 0.0;
   out_4199070111182038978[55] = 0.0;
   out_4199070111182038978[56] = 0.0;
   out_4199070111182038978[57] = 1.0;
   out_4199070111182038978[58] = 0.0;
   out_4199070111182038978[59] = 0.0;
   out_4199070111182038978[60] = 0.0;
   out_4199070111182038978[61] = 0.0;
   out_4199070111182038978[62] = 0.0;
   out_4199070111182038978[63] = 0.0;
   out_4199070111182038978[64] = 0.0;
   out_4199070111182038978[65] = 0.0;
   out_4199070111182038978[66] = 0.0;
   out_4199070111182038978[67] = 0.0;
   out_4199070111182038978[68] = 0.0;
   out_4199070111182038978[69] = 0.0;
   out_4199070111182038978[70] = 0.0;
   out_4199070111182038978[71] = 0.0;
   out_4199070111182038978[72] = 0.0;
   out_4199070111182038978[73] = 0.0;
   out_4199070111182038978[74] = 0.0;
   out_4199070111182038978[75] = 0.0;
   out_4199070111182038978[76] = 1.0;
   out_4199070111182038978[77] = 0.0;
   out_4199070111182038978[78] = 0.0;
   out_4199070111182038978[79] = 0.0;
   out_4199070111182038978[80] = 0.0;
   out_4199070111182038978[81] = 0.0;
   out_4199070111182038978[82] = 0.0;
   out_4199070111182038978[83] = 0.0;
   out_4199070111182038978[84] = 0.0;
   out_4199070111182038978[85] = 0.0;
   out_4199070111182038978[86] = 0.0;
   out_4199070111182038978[87] = 0.0;
   out_4199070111182038978[88] = 0.0;
   out_4199070111182038978[89] = 0.0;
   out_4199070111182038978[90] = 0.0;
   out_4199070111182038978[91] = 0.0;
   out_4199070111182038978[92] = 0.0;
   out_4199070111182038978[93] = 0.0;
   out_4199070111182038978[94] = 0.0;
   out_4199070111182038978[95] = 1.0;
   out_4199070111182038978[96] = 0.0;
   out_4199070111182038978[97] = 0.0;
   out_4199070111182038978[98] = 0.0;
   out_4199070111182038978[99] = 0.0;
   out_4199070111182038978[100] = 0.0;
   out_4199070111182038978[101] = 0.0;
   out_4199070111182038978[102] = 0.0;
   out_4199070111182038978[103] = 0.0;
   out_4199070111182038978[104] = 0.0;
   out_4199070111182038978[105] = 0.0;
   out_4199070111182038978[106] = 0.0;
   out_4199070111182038978[107] = 0.0;
   out_4199070111182038978[108] = 0.0;
   out_4199070111182038978[109] = 0.0;
   out_4199070111182038978[110] = 0.0;
   out_4199070111182038978[111] = 0.0;
   out_4199070111182038978[112] = 0.0;
   out_4199070111182038978[113] = 0.0;
   out_4199070111182038978[114] = 1.0;
   out_4199070111182038978[115] = 0.0;
   out_4199070111182038978[116] = 0.0;
   out_4199070111182038978[117] = 0.0;
   out_4199070111182038978[118] = 0.0;
   out_4199070111182038978[119] = 0.0;
   out_4199070111182038978[120] = 0.0;
   out_4199070111182038978[121] = 0.0;
   out_4199070111182038978[122] = 0.0;
   out_4199070111182038978[123] = 0.0;
   out_4199070111182038978[124] = 0.0;
   out_4199070111182038978[125] = 0.0;
   out_4199070111182038978[126] = 0.0;
   out_4199070111182038978[127] = 0.0;
   out_4199070111182038978[128] = 0.0;
   out_4199070111182038978[129] = 0.0;
   out_4199070111182038978[130] = 0.0;
   out_4199070111182038978[131] = 0.0;
   out_4199070111182038978[132] = 0.0;
   out_4199070111182038978[133] = 1.0;
   out_4199070111182038978[134] = 0.0;
   out_4199070111182038978[135] = 0.0;
   out_4199070111182038978[136] = 0.0;
   out_4199070111182038978[137] = 0.0;
   out_4199070111182038978[138] = 0.0;
   out_4199070111182038978[139] = 0.0;
   out_4199070111182038978[140] = 0.0;
   out_4199070111182038978[141] = 0.0;
   out_4199070111182038978[142] = 0.0;
   out_4199070111182038978[143] = 0.0;
   out_4199070111182038978[144] = 0.0;
   out_4199070111182038978[145] = 0.0;
   out_4199070111182038978[146] = 0.0;
   out_4199070111182038978[147] = 0.0;
   out_4199070111182038978[148] = 0.0;
   out_4199070111182038978[149] = 0.0;
   out_4199070111182038978[150] = 0.0;
   out_4199070111182038978[151] = 0.0;
   out_4199070111182038978[152] = 1.0;
   out_4199070111182038978[153] = 0.0;
   out_4199070111182038978[154] = 0.0;
   out_4199070111182038978[155] = 0.0;
   out_4199070111182038978[156] = 0.0;
   out_4199070111182038978[157] = 0.0;
   out_4199070111182038978[158] = 0.0;
   out_4199070111182038978[159] = 0.0;
   out_4199070111182038978[160] = 0.0;
   out_4199070111182038978[161] = 0.0;
   out_4199070111182038978[162] = 0.0;
   out_4199070111182038978[163] = 0.0;
   out_4199070111182038978[164] = 0.0;
   out_4199070111182038978[165] = 0.0;
   out_4199070111182038978[166] = 0.0;
   out_4199070111182038978[167] = 0.0;
   out_4199070111182038978[168] = 0.0;
   out_4199070111182038978[169] = 0.0;
   out_4199070111182038978[170] = 0.0;
   out_4199070111182038978[171] = 1.0;
   out_4199070111182038978[172] = 0.0;
   out_4199070111182038978[173] = 0.0;
   out_4199070111182038978[174] = 0.0;
   out_4199070111182038978[175] = 0.0;
   out_4199070111182038978[176] = 0.0;
   out_4199070111182038978[177] = 0.0;
   out_4199070111182038978[178] = 0.0;
   out_4199070111182038978[179] = 0.0;
   out_4199070111182038978[180] = 0.0;
   out_4199070111182038978[181] = 0.0;
   out_4199070111182038978[182] = 0.0;
   out_4199070111182038978[183] = 0.0;
   out_4199070111182038978[184] = 0.0;
   out_4199070111182038978[185] = 0.0;
   out_4199070111182038978[186] = 0.0;
   out_4199070111182038978[187] = 0.0;
   out_4199070111182038978[188] = 0.0;
   out_4199070111182038978[189] = 0.0;
   out_4199070111182038978[190] = 1.0;
   out_4199070111182038978[191] = 0.0;
   out_4199070111182038978[192] = 0.0;
   out_4199070111182038978[193] = 0.0;
   out_4199070111182038978[194] = 0.0;
   out_4199070111182038978[195] = 0.0;
   out_4199070111182038978[196] = 0.0;
   out_4199070111182038978[197] = 0.0;
   out_4199070111182038978[198] = 0.0;
   out_4199070111182038978[199] = 0.0;
   out_4199070111182038978[200] = 0.0;
   out_4199070111182038978[201] = 0.0;
   out_4199070111182038978[202] = 0.0;
   out_4199070111182038978[203] = 0.0;
   out_4199070111182038978[204] = 0.0;
   out_4199070111182038978[205] = 0.0;
   out_4199070111182038978[206] = 0.0;
   out_4199070111182038978[207] = 0.0;
   out_4199070111182038978[208] = 0.0;
   out_4199070111182038978[209] = 1.0;
   out_4199070111182038978[210] = 0.0;
   out_4199070111182038978[211] = 0.0;
   out_4199070111182038978[212] = 0.0;
   out_4199070111182038978[213] = 0.0;
   out_4199070111182038978[214] = 0.0;
   out_4199070111182038978[215] = 0.0;
   out_4199070111182038978[216] = 0.0;
   out_4199070111182038978[217] = 0.0;
   out_4199070111182038978[218] = 0.0;
   out_4199070111182038978[219] = 0.0;
   out_4199070111182038978[220] = 0.0;
   out_4199070111182038978[221] = 0.0;
   out_4199070111182038978[222] = 0.0;
   out_4199070111182038978[223] = 0.0;
   out_4199070111182038978[224] = 0.0;
   out_4199070111182038978[225] = 0.0;
   out_4199070111182038978[226] = 0.0;
   out_4199070111182038978[227] = 0.0;
   out_4199070111182038978[228] = 1.0;
   out_4199070111182038978[229] = 0.0;
   out_4199070111182038978[230] = 0.0;
   out_4199070111182038978[231] = 0.0;
   out_4199070111182038978[232] = 0.0;
   out_4199070111182038978[233] = 0.0;
   out_4199070111182038978[234] = 0.0;
   out_4199070111182038978[235] = 0.0;
   out_4199070111182038978[236] = 0.0;
   out_4199070111182038978[237] = 0.0;
   out_4199070111182038978[238] = 0.0;
   out_4199070111182038978[239] = 0.0;
   out_4199070111182038978[240] = 0.0;
   out_4199070111182038978[241] = 0.0;
   out_4199070111182038978[242] = 0.0;
   out_4199070111182038978[243] = 0.0;
   out_4199070111182038978[244] = 0.0;
   out_4199070111182038978[245] = 0.0;
   out_4199070111182038978[246] = 0.0;
   out_4199070111182038978[247] = 1.0;
   out_4199070111182038978[248] = 0.0;
   out_4199070111182038978[249] = 0.0;
   out_4199070111182038978[250] = 0.0;
   out_4199070111182038978[251] = 0.0;
   out_4199070111182038978[252] = 0.0;
   out_4199070111182038978[253] = 0.0;
   out_4199070111182038978[254] = 0.0;
   out_4199070111182038978[255] = 0.0;
   out_4199070111182038978[256] = 0.0;
   out_4199070111182038978[257] = 0.0;
   out_4199070111182038978[258] = 0.0;
   out_4199070111182038978[259] = 0.0;
   out_4199070111182038978[260] = 0.0;
   out_4199070111182038978[261] = 0.0;
   out_4199070111182038978[262] = 0.0;
   out_4199070111182038978[263] = 0.0;
   out_4199070111182038978[264] = 0.0;
   out_4199070111182038978[265] = 0.0;
   out_4199070111182038978[266] = 1.0;
   out_4199070111182038978[267] = 0.0;
   out_4199070111182038978[268] = 0.0;
   out_4199070111182038978[269] = 0.0;
   out_4199070111182038978[270] = 0.0;
   out_4199070111182038978[271] = 0.0;
   out_4199070111182038978[272] = 0.0;
   out_4199070111182038978[273] = 0.0;
   out_4199070111182038978[274] = 0.0;
   out_4199070111182038978[275] = 0.0;
   out_4199070111182038978[276] = 0.0;
   out_4199070111182038978[277] = 0.0;
   out_4199070111182038978[278] = 0.0;
   out_4199070111182038978[279] = 0.0;
   out_4199070111182038978[280] = 0.0;
   out_4199070111182038978[281] = 0.0;
   out_4199070111182038978[282] = 0.0;
   out_4199070111182038978[283] = 0.0;
   out_4199070111182038978[284] = 0.0;
   out_4199070111182038978[285] = 1.0;
   out_4199070111182038978[286] = 0.0;
   out_4199070111182038978[287] = 0.0;
   out_4199070111182038978[288] = 0.0;
   out_4199070111182038978[289] = 0.0;
   out_4199070111182038978[290] = 0.0;
   out_4199070111182038978[291] = 0.0;
   out_4199070111182038978[292] = 0.0;
   out_4199070111182038978[293] = 0.0;
   out_4199070111182038978[294] = 0.0;
   out_4199070111182038978[295] = 0.0;
   out_4199070111182038978[296] = 0.0;
   out_4199070111182038978[297] = 0.0;
   out_4199070111182038978[298] = 0.0;
   out_4199070111182038978[299] = 0.0;
   out_4199070111182038978[300] = 0.0;
   out_4199070111182038978[301] = 0.0;
   out_4199070111182038978[302] = 0.0;
   out_4199070111182038978[303] = 0.0;
   out_4199070111182038978[304] = 1.0;
   out_4199070111182038978[305] = 0.0;
   out_4199070111182038978[306] = 0.0;
   out_4199070111182038978[307] = 0.0;
   out_4199070111182038978[308] = 0.0;
   out_4199070111182038978[309] = 0.0;
   out_4199070111182038978[310] = 0.0;
   out_4199070111182038978[311] = 0.0;
   out_4199070111182038978[312] = 0.0;
   out_4199070111182038978[313] = 0.0;
   out_4199070111182038978[314] = 0.0;
   out_4199070111182038978[315] = 0.0;
   out_4199070111182038978[316] = 0.0;
   out_4199070111182038978[317] = 0.0;
   out_4199070111182038978[318] = 0.0;
   out_4199070111182038978[319] = 0.0;
   out_4199070111182038978[320] = 0.0;
   out_4199070111182038978[321] = 0.0;
   out_4199070111182038978[322] = 0.0;
   out_4199070111182038978[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7514380099440619472) {
   out_7514380099440619472[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7514380099440619472[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7514380099440619472[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7514380099440619472[3] = dt*state[12] + state[3];
   out_7514380099440619472[4] = dt*state[13] + state[4];
   out_7514380099440619472[5] = dt*state[14] + state[5];
   out_7514380099440619472[6] = state[6];
   out_7514380099440619472[7] = state[7];
   out_7514380099440619472[8] = state[8];
   out_7514380099440619472[9] = state[9];
   out_7514380099440619472[10] = state[10];
   out_7514380099440619472[11] = state[11];
   out_7514380099440619472[12] = state[12];
   out_7514380099440619472[13] = state[13];
   out_7514380099440619472[14] = state[14];
   out_7514380099440619472[15] = state[15];
   out_7514380099440619472[16] = state[16];
   out_7514380099440619472[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8168825780265645912) {
   out_8168825780265645912[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8168825780265645912[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8168825780265645912[2] = 0;
   out_8168825780265645912[3] = 0;
   out_8168825780265645912[4] = 0;
   out_8168825780265645912[5] = 0;
   out_8168825780265645912[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8168825780265645912[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8168825780265645912[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8168825780265645912[9] = 0;
   out_8168825780265645912[10] = 0;
   out_8168825780265645912[11] = 0;
   out_8168825780265645912[12] = 0;
   out_8168825780265645912[13] = 0;
   out_8168825780265645912[14] = 0;
   out_8168825780265645912[15] = 0;
   out_8168825780265645912[16] = 0;
   out_8168825780265645912[17] = 0;
   out_8168825780265645912[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8168825780265645912[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8168825780265645912[20] = 0;
   out_8168825780265645912[21] = 0;
   out_8168825780265645912[22] = 0;
   out_8168825780265645912[23] = 0;
   out_8168825780265645912[24] = 0;
   out_8168825780265645912[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8168825780265645912[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8168825780265645912[27] = 0;
   out_8168825780265645912[28] = 0;
   out_8168825780265645912[29] = 0;
   out_8168825780265645912[30] = 0;
   out_8168825780265645912[31] = 0;
   out_8168825780265645912[32] = 0;
   out_8168825780265645912[33] = 0;
   out_8168825780265645912[34] = 0;
   out_8168825780265645912[35] = 0;
   out_8168825780265645912[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8168825780265645912[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8168825780265645912[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8168825780265645912[39] = 0;
   out_8168825780265645912[40] = 0;
   out_8168825780265645912[41] = 0;
   out_8168825780265645912[42] = 0;
   out_8168825780265645912[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8168825780265645912[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8168825780265645912[45] = 0;
   out_8168825780265645912[46] = 0;
   out_8168825780265645912[47] = 0;
   out_8168825780265645912[48] = 0;
   out_8168825780265645912[49] = 0;
   out_8168825780265645912[50] = 0;
   out_8168825780265645912[51] = 0;
   out_8168825780265645912[52] = 0;
   out_8168825780265645912[53] = 0;
   out_8168825780265645912[54] = 0;
   out_8168825780265645912[55] = 0;
   out_8168825780265645912[56] = 0;
   out_8168825780265645912[57] = 1;
   out_8168825780265645912[58] = 0;
   out_8168825780265645912[59] = 0;
   out_8168825780265645912[60] = 0;
   out_8168825780265645912[61] = 0;
   out_8168825780265645912[62] = 0;
   out_8168825780265645912[63] = 0;
   out_8168825780265645912[64] = 0;
   out_8168825780265645912[65] = 0;
   out_8168825780265645912[66] = dt;
   out_8168825780265645912[67] = 0;
   out_8168825780265645912[68] = 0;
   out_8168825780265645912[69] = 0;
   out_8168825780265645912[70] = 0;
   out_8168825780265645912[71] = 0;
   out_8168825780265645912[72] = 0;
   out_8168825780265645912[73] = 0;
   out_8168825780265645912[74] = 0;
   out_8168825780265645912[75] = 0;
   out_8168825780265645912[76] = 1;
   out_8168825780265645912[77] = 0;
   out_8168825780265645912[78] = 0;
   out_8168825780265645912[79] = 0;
   out_8168825780265645912[80] = 0;
   out_8168825780265645912[81] = 0;
   out_8168825780265645912[82] = 0;
   out_8168825780265645912[83] = 0;
   out_8168825780265645912[84] = 0;
   out_8168825780265645912[85] = dt;
   out_8168825780265645912[86] = 0;
   out_8168825780265645912[87] = 0;
   out_8168825780265645912[88] = 0;
   out_8168825780265645912[89] = 0;
   out_8168825780265645912[90] = 0;
   out_8168825780265645912[91] = 0;
   out_8168825780265645912[92] = 0;
   out_8168825780265645912[93] = 0;
   out_8168825780265645912[94] = 0;
   out_8168825780265645912[95] = 1;
   out_8168825780265645912[96] = 0;
   out_8168825780265645912[97] = 0;
   out_8168825780265645912[98] = 0;
   out_8168825780265645912[99] = 0;
   out_8168825780265645912[100] = 0;
   out_8168825780265645912[101] = 0;
   out_8168825780265645912[102] = 0;
   out_8168825780265645912[103] = 0;
   out_8168825780265645912[104] = dt;
   out_8168825780265645912[105] = 0;
   out_8168825780265645912[106] = 0;
   out_8168825780265645912[107] = 0;
   out_8168825780265645912[108] = 0;
   out_8168825780265645912[109] = 0;
   out_8168825780265645912[110] = 0;
   out_8168825780265645912[111] = 0;
   out_8168825780265645912[112] = 0;
   out_8168825780265645912[113] = 0;
   out_8168825780265645912[114] = 1;
   out_8168825780265645912[115] = 0;
   out_8168825780265645912[116] = 0;
   out_8168825780265645912[117] = 0;
   out_8168825780265645912[118] = 0;
   out_8168825780265645912[119] = 0;
   out_8168825780265645912[120] = 0;
   out_8168825780265645912[121] = 0;
   out_8168825780265645912[122] = 0;
   out_8168825780265645912[123] = 0;
   out_8168825780265645912[124] = 0;
   out_8168825780265645912[125] = 0;
   out_8168825780265645912[126] = 0;
   out_8168825780265645912[127] = 0;
   out_8168825780265645912[128] = 0;
   out_8168825780265645912[129] = 0;
   out_8168825780265645912[130] = 0;
   out_8168825780265645912[131] = 0;
   out_8168825780265645912[132] = 0;
   out_8168825780265645912[133] = 1;
   out_8168825780265645912[134] = 0;
   out_8168825780265645912[135] = 0;
   out_8168825780265645912[136] = 0;
   out_8168825780265645912[137] = 0;
   out_8168825780265645912[138] = 0;
   out_8168825780265645912[139] = 0;
   out_8168825780265645912[140] = 0;
   out_8168825780265645912[141] = 0;
   out_8168825780265645912[142] = 0;
   out_8168825780265645912[143] = 0;
   out_8168825780265645912[144] = 0;
   out_8168825780265645912[145] = 0;
   out_8168825780265645912[146] = 0;
   out_8168825780265645912[147] = 0;
   out_8168825780265645912[148] = 0;
   out_8168825780265645912[149] = 0;
   out_8168825780265645912[150] = 0;
   out_8168825780265645912[151] = 0;
   out_8168825780265645912[152] = 1;
   out_8168825780265645912[153] = 0;
   out_8168825780265645912[154] = 0;
   out_8168825780265645912[155] = 0;
   out_8168825780265645912[156] = 0;
   out_8168825780265645912[157] = 0;
   out_8168825780265645912[158] = 0;
   out_8168825780265645912[159] = 0;
   out_8168825780265645912[160] = 0;
   out_8168825780265645912[161] = 0;
   out_8168825780265645912[162] = 0;
   out_8168825780265645912[163] = 0;
   out_8168825780265645912[164] = 0;
   out_8168825780265645912[165] = 0;
   out_8168825780265645912[166] = 0;
   out_8168825780265645912[167] = 0;
   out_8168825780265645912[168] = 0;
   out_8168825780265645912[169] = 0;
   out_8168825780265645912[170] = 0;
   out_8168825780265645912[171] = 1;
   out_8168825780265645912[172] = 0;
   out_8168825780265645912[173] = 0;
   out_8168825780265645912[174] = 0;
   out_8168825780265645912[175] = 0;
   out_8168825780265645912[176] = 0;
   out_8168825780265645912[177] = 0;
   out_8168825780265645912[178] = 0;
   out_8168825780265645912[179] = 0;
   out_8168825780265645912[180] = 0;
   out_8168825780265645912[181] = 0;
   out_8168825780265645912[182] = 0;
   out_8168825780265645912[183] = 0;
   out_8168825780265645912[184] = 0;
   out_8168825780265645912[185] = 0;
   out_8168825780265645912[186] = 0;
   out_8168825780265645912[187] = 0;
   out_8168825780265645912[188] = 0;
   out_8168825780265645912[189] = 0;
   out_8168825780265645912[190] = 1;
   out_8168825780265645912[191] = 0;
   out_8168825780265645912[192] = 0;
   out_8168825780265645912[193] = 0;
   out_8168825780265645912[194] = 0;
   out_8168825780265645912[195] = 0;
   out_8168825780265645912[196] = 0;
   out_8168825780265645912[197] = 0;
   out_8168825780265645912[198] = 0;
   out_8168825780265645912[199] = 0;
   out_8168825780265645912[200] = 0;
   out_8168825780265645912[201] = 0;
   out_8168825780265645912[202] = 0;
   out_8168825780265645912[203] = 0;
   out_8168825780265645912[204] = 0;
   out_8168825780265645912[205] = 0;
   out_8168825780265645912[206] = 0;
   out_8168825780265645912[207] = 0;
   out_8168825780265645912[208] = 0;
   out_8168825780265645912[209] = 1;
   out_8168825780265645912[210] = 0;
   out_8168825780265645912[211] = 0;
   out_8168825780265645912[212] = 0;
   out_8168825780265645912[213] = 0;
   out_8168825780265645912[214] = 0;
   out_8168825780265645912[215] = 0;
   out_8168825780265645912[216] = 0;
   out_8168825780265645912[217] = 0;
   out_8168825780265645912[218] = 0;
   out_8168825780265645912[219] = 0;
   out_8168825780265645912[220] = 0;
   out_8168825780265645912[221] = 0;
   out_8168825780265645912[222] = 0;
   out_8168825780265645912[223] = 0;
   out_8168825780265645912[224] = 0;
   out_8168825780265645912[225] = 0;
   out_8168825780265645912[226] = 0;
   out_8168825780265645912[227] = 0;
   out_8168825780265645912[228] = 1;
   out_8168825780265645912[229] = 0;
   out_8168825780265645912[230] = 0;
   out_8168825780265645912[231] = 0;
   out_8168825780265645912[232] = 0;
   out_8168825780265645912[233] = 0;
   out_8168825780265645912[234] = 0;
   out_8168825780265645912[235] = 0;
   out_8168825780265645912[236] = 0;
   out_8168825780265645912[237] = 0;
   out_8168825780265645912[238] = 0;
   out_8168825780265645912[239] = 0;
   out_8168825780265645912[240] = 0;
   out_8168825780265645912[241] = 0;
   out_8168825780265645912[242] = 0;
   out_8168825780265645912[243] = 0;
   out_8168825780265645912[244] = 0;
   out_8168825780265645912[245] = 0;
   out_8168825780265645912[246] = 0;
   out_8168825780265645912[247] = 1;
   out_8168825780265645912[248] = 0;
   out_8168825780265645912[249] = 0;
   out_8168825780265645912[250] = 0;
   out_8168825780265645912[251] = 0;
   out_8168825780265645912[252] = 0;
   out_8168825780265645912[253] = 0;
   out_8168825780265645912[254] = 0;
   out_8168825780265645912[255] = 0;
   out_8168825780265645912[256] = 0;
   out_8168825780265645912[257] = 0;
   out_8168825780265645912[258] = 0;
   out_8168825780265645912[259] = 0;
   out_8168825780265645912[260] = 0;
   out_8168825780265645912[261] = 0;
   out_8168825780265645912[262] = 0;
   out_8168825780265645912[263] = 0;
   out_8168825780265645912[264] = 0;
   out_8168825780265645912[265] = 0;
   out_8168825780265645912[266] = 1;
   out_8168825780265645912[267] = 0;
   out_8168825780265645912[268] = 0;
   out_8168825780265645912[269] = 0;
   out_8168825780265645912[270] = 0;
   out_8168825780265645912[271] = 0;
   out_8168825780265645912[272] = 0;
   out_8168825780265645912[273] = 0;
   out_8168825780265645912[274] = 0;
   out_8168825780265645912[275] = 0;
   out_8168825780265645912[276] = 0;
   out_8168825780265645912[277] = 0;
   out_8168825780265645912[278] = 0;
   out_8168825780265645912[279] = 0;
   out_8168825780265645912[280] = 0;
   out_8168825780265645912[281] = 0;
   out_8168825780265645912[282] = 0;
   out_8168825780265645912[283] = 0;
   out_8168825780265645912[284] = 0;
   out_8168825780265645912[285] = 1;
   out_8168825780265645912[286] = 0;
   out_8168825780265645912[287] = 0;
   out_8168825780265645912[288] = 0;
   out_8168825780265645912[289] = 0;
   out_8168825780265645912[290] = 0;
   out_8168825780265645912[291] = 0;
   out_8168825780265645912[292] = 0;
   out_8168825780265645912[293] = 0;
   out_8168825780265645912[294] = 0;
   out_8168825780265645912[295] = 0;
   out_8168825780265645912[296] = 0;
   out_8168825780265645912[297] = 0;
   out_8168825780265645912[298] = 0;
   out_8168825780265645912[299] = 0;
   out_8168825780265645912[300] = 0;
   out_8168825780265645912[301] = 0;
   out_8168825780265645912[302] = 0;
   out_8168825780265645912[303] = 0;
   out_8168825780265645912[304] = 1;
   out_8168825780265645912[305] = 0;
   out_8168825780265645912[306] = 0;
   out_8168825780265645912[307] = 0;
   out_8168825780265645912[308] = 0;
   out_8168825780265645912[309] = 0;
   out_8168825780265645912[310] = 0;
   out_8168825780265645912[311] = 0;
   out_8168825780265645912[312] = 0;
   out_8168825780265645912[313] = 0;
   out_8168825780265645912[314] = 0;
   out_8168825780265645912[315] = 0;
   out_8168825780265645912[316] = 0;
   out_8168825780265645912[317] = 0;
   out_8168825780265645912[318] = 0;
   out_8168825780265645912[319] = 0;
   out_8168825780265645912[320] = 0;
   out_8168825780265645912[321] = 0;
   out_8168825780265645912[322] = 0;
   out_8168825780265645912[323] = 1;
}
void h_4(double *state, double *unused, double *out_8652272607369950630) {
   out_8652272607369950630[0] = state[6] + state[9];
   out_8652272607369950630[1] = state[7] + state[10];
   out_8652272607369950630[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7970877321025946550) {
   out_7970877321025946550[0] = 0;
   out_7970877321025946550[1] = 0;
   out_7970877321025946550[2] = 0;
   out_7970877321025946550[3] = 0;
   out_7970877321025946550[4] = 0;
   out_7970877321025946550[5] = 0;
   out_7970877321025946550[6] = 1;
   out_7970877321025946550[7] = 0;
   out_7970877321025946550[8] = 0;
   out_7970877321025946550[9] = 1;
   out_7970877321025946550[10] = 0;
   out_7970877321025946550[11] = 0;
   out_7970877321025946550[12] = 0;
   out_7970877321025946550[13] = 0;
   out_7970877321025946550[14] = 0;
   out_7970877321025946550[15] = 0;
   out_7970877321025946550[16] = 0;
   out_7970877321025946550[17] = 0;
   out_7970877321025946550[18] = 0;
   out_7970877321025946550[19] = 0;
   out_7970877321025946550[20] = 0;
   out_7970877321025946550[21] = 0;
   out_7970877321025946550[22] = 0;
   out_7970877321025946550[23] = 0;
   out_7970877321025946550[24] = 0;
   out_7970877321025946550[25] = 1;
   out_7970877321025946550[26] = 0;
   out_7970877321025946550[27] = 0;
   out_7970877321025946550[28] = 1;
   out_7970877321025946550[29] = 0;
   out_7970877321025946550[30] = 0;
   out_7970877321025946550[31] = 0;
   out_7970877321025946550[32] = 0;
   out_7970877321025946550[33] = 0;
   out_7970877321025946550[34] = 0;
   out_7970877321025946550[35] = 0;
   out_7970877321025946550[36] = 0;
   out_7970877321025946550[37] = 0;
   out_7970877321025946550[38] = 0;
   out_7970877321025946550[39] = 0;
   out_7970877321025946550[40] = 0;
   out_7970877321025946550[41] = 0;
   out_7970877321025946550[42] = 0;
   out_7970877321025946550[43] = 0;
   out_7970877321025946550[44] = 1;
   out_7970877321025946550[45] = 0;
   out_7970877321025946550[46] = 0;
   out_7970877321025946550[47] = 1;
   out_7970877321025946550[48] = 0;
   out_7970877321025946550[49] = 0;
   out_7970877321025946550[50] = 0;
   out_7970877321025946550[51] = 0;
   out_7970877321025946550[52] = 0;
   out_7970877321025946550[53] = 0;
}
void h_10(double *state, double *unused, double *out_9075670553093884606) {
   out_9075670553093884606[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_9075670553093884606[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_9075670553093884606[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4573840938451450228) {
   out_4573840938451450228[0] = 0;
   out_4573840938451450228[1] = 9.8100000000000005*cos(state[1]);
   out_4573840938451450228[2] = 0;
   out_4573840938451450228[3] = 0;
   out_4573840938451450228[4] = -state[8];
   out_4573840938451450228[5] = state[7];
   out_4573840938451450228[6] = 0;
   out_4573840938451450228[7] = state[5];
   out_4573840938451450228[8] = -state[4];
   out_4573840938451450228[9] = 0;
   out_4573840938451450228[10] = 0;
   out_4573840938451450228[11] = 0;
   out_4573840938451450228[12] = 1;
   out_4573840938451450228[13] = 0;
   out_4573840938451450228[14] = 0;
   out_4573840938451450228[15] = 1;
   out_4573840938451450228[16] = 0;
   out_4573840938451450228[17] = 0;
   out_4573840938451450228[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4573840938451450228[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4573840938451450228[20] = 0;
   out_4573840938451450228[21] = state[8];
   out_4573840938451450228[22] = 0;
   out_4573840938451450228[23] = -state[6];
   out_4573840938451450228[24] = -state[5];
   out_4573840938451450228[25] = 0;
   out_4573840938451450228[26] = state[3];
   out_4573840938451450228[27] = 0;
   out_4573840938451450228[28] = 0;
   out_4573840938451450228[29] = 0;
   out_4573840938451450228[30] = 0;
   out_4573840938451450228[31] = 1;
   out_4573840938451450228[32] = 0;
   out_4573840938451450228[33] = 0;
   out_4573840938451450228[34] = 1;
   out_4573840938451450228[35] = 0;
   out_4573840938451450228[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4573840938451450228[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4573840938451450228[38] = 0;
   out_4573840938451450228[39] = -state[7];
   out_4573840938451450228[40] = state[6];
   out_4573840938451450228[41] = 0;
   out_4573840938451450228[42] = state[4];
   out_4573840938451450228[43] = -state[3];
   out_4573840938451450228[44] = 0;
   out_4573840938451450228[45] = 0;
   out_4573840938451450228[46] = 0;
   out_4573840938451450228[47] = 0;
   out_4573840938451450228[48] = 0;
   out_4573840938451450228[49] = 0;
   out_4573840938451450228[50] = 1;
   out_4573840938451450228[51] = 0;
   out_4573840938451450228[52] = 0;
   out_4573840938451450228[53] = 1;
}
void h_13(double *state, double *unused, double *out_6456544963748931363) {
   out_6456544963748931363[0] = state[3];
   out_6456544963748931363[1] = state[4];
   out_6456544963748931363[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7263592927351272265) {
   out_7263592927351272265[0] = 0;
   out_7263592927351272265[1] = 0;
   out_7263592927351272265[2] = 0;
   out_7263592927351272265[3] = 1;
   out_7263592927351272265[4] = 0;
   out_7263592927351272265[5] = 0;
   out_7263592927351272265[6] = 0;
   out_7263592927351272265[7] = 0;
   out_7263592927351272265[8] = 0;
   out_7263592927351272265[9] = 0;
   out_7263592927351272265[10] = 0;
   out_7263592927351272265[11] = 0;
   out_7263592927351272265[12] = 0;
   out_7263592927351272265[13] = 0;
   out_7263592927351272265[14] = 0;
   out_7263592927351272265[15] = 0;
   out_7263592927351272265[16] = 0;
   out_7263592927351272265[17] = 0;
   out_7263592927351272265[18] = 0;
   out_7263592927351272265[19] = 0;
   out_7263592927351272265[20] = 0;
   out_7263592927351272265[21] = 0;
   out_7263592927351272265[22] = 1;
   out_7263592927351272265[23] = 0;
   out_7263592927351272265[24] = 0;
   out_7263592927351272265[25] = 0;
   out_7263592927351272265[26] = 0;
   out_7263592927351272265[27] = 0;
   out_7263592927351272265[28] = 0;
   out_7263592927351272265[29] = 0;
   out_7263592927351272265[30] = 0;
   out_7263592927351272265[31] = 0;
   out_7263592927351272265[32] = 0;
   out_7263592927351272265[33] = 0;
   out_7263592927351272265[34] = 0;
   out_7263592927351272265[35] = 0;
   out_7263592927351272265[36] = 0;
   out_7263592927351272265[37] = 0;
   out_7263592927351272265[38] = 0;
   out_7263592927351272265[39] = 0;
   out_7263592927351272265[40] = 0;
   out_7263592927351272265[41] = 1;
   out_7263592927351272265[42] = 0;
   out_7263592927351272265[43] = 0;
   out_7263592927351272265[44] = 0;
   out_7263592927351272265[45] = 0;
   out_7263592927351272265[46] = 0;
   out_7263592927351272265[47] = 0;
   out_7263592927351272265[48] = 0;
   out_7263592927351272265[49] = 0;
   out_7263592927351272265[50] = 0;
   out_7263592927351272265[51] = 0;
   out_7263592927351272265[52] = 0;
   out_7263592927351272265[53] = 0;
}
void h_14(double *state, double *unused, double *out_8577904112370749384) {
   out_8577904112370749384[0] = state[6];
   out_8577904112370749384[1] = state[7];
   out_8577904112370749384[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6512625896344120537) {
   out_6512625896344120537[0] = 0;
   out_6512625896344120537[1] = 0;
   out_6512625896344120537[2] = 0;
   out_6512625896344120537[3] = 0;
   out_6512625896344120537[4] = 0;
   out_6512625896344120537[5] = 0;
   out_6512625896344120537[6] = 1;
   out_6512625896344120537[7] = 0;
   out_6512625896344120537[8] = 0;
   out_6512625896344120537[9] = 0;
   out_6512625896344120537[10] = 0;
   out_6512625896344120537[11] = 0;
   out_6512625896344120537[12] = 0;
   out_6512625896344120537[13] = 0;
   out_6512625896344120537[14] = 0;
   out_6512625896344120537[15] = 0;
   out_6512625896344120537[16] = 0;
   out_6512625896344120537[17] = 0;
   out_6512625896344120537[18] = 0;
   out_6512625896344120537[19] = 0;
   out_6512625896344120537[20] = 0;
   out_6512625896344120537[21] = 0;
   out_6512625896344120537[22] = 0;
   out_6512625896344120537[23] = 0;
   out_6512625896344120537[24] = 0;
   out_6512625896344120537[25] = 1;
   out_6512625896344120537[26] = 0;
   out_6512625896344120537[27] = 0;
   out_6512625896344120537[28] = 0;
   out_6512625896344120537[29] = 0;
   out_6512625896344120537[30] = 0;
   out_6512625896344120537[31] = 0;
   out_6512625896344120537[32] = 0;
   out_6512625896344120537[33] = 0;
   out_6512625896344120537[34] = 0;
   out_6512625896344120537[35] = 0;
   out_6512625896344120537[36] = 0;
   out_6512625896344120537[37] = 0;
   out_6512625896344120537[38] = 0;
   out_6512625896344120537[39] = 0;
   out_6512625896344120537[40] = 0;
   out_6512625896344120537[41] = 0;
   out_6512625896344120537[42] = 0;
   out_6512625896344120537[43] = 0;
   out_6512625896344120537[44] = 1;
   out_6512625896344120537[45] = 0;
   out_6512625896344120537[46] = 0;
   out_6512625896344120537[47] = 0;
   out_6512625896344120537[48] = 0;
   out_6512625896344120537[49] = 0;
   out_6512625896344120537[50] = 0;
   out_6512625896344120537[51] = 0;
   out_6512625896344120537[52] = 0;
   out_6512625896344120537[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8222070877202252563) {
  err_fun(nom_x, delta_x, out_8222070877202252563);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7433102429512158712) {
  inv_err_fun(nom_x, true_x, out_7433102429512158712);
}
void pose_H_mod_fun(double *state, double *out_4199070111182038978) {
  H_mod_fun(state, out_4199070111182038978);
}
void pose_f_fun(double *state, double dt, double *out_7514380099440619472) {
  f_fun(state,  dt, out_7514380099440619472);
}
void pose_F_fun(double *state, double dt, double *out_8168825780265645912) {
  F_fun(state,  dt, out_8168825780265645912);
}
void pose_h_4(double *state, double *unused, double *out_8652272607369950630) {
  h_4(state, unused, out_8652272607369950630);
}
void pose_H_4(double *state, double *unused, double *out_7970877321025946550) {
  H_4(state, unused, out_7970877321025946550);
}
void pose_h_10(double *state, double *unused, double *out_9075670553093884606) {
  h_10(state, unused, out_9075670553093884606);
}
void pose_H_10(double *state, double *unused, double *out_4573840938451450228) {
  H_10(state, unused, out_4573840938451450228);
}
void pose_h_13(double *state, double *unused, double *out_6456544963748931363) {
  h_13(state, unused, out_6456544963748931363);
}
void pose_H_13(double *state, double *unused, double *out_7263592927351272265) {
  H_13(state, unused, out_7263592927351272265);
}
void pose_h_14(double *state, double *unused, double *out_8577904112370749384) {
  h_14(state, unused, out_8577904112370749384);
}
void pose_H_14(double *state, double *unused, double *out_6512625896344120537) {
  H_14(state, unused, out_6512625896344120537);
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
