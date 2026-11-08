#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8222070877202252563);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7433102429512158712);
void pose_H_mod_fun(double *state, double *out_4199070111182038978);
void pose_f_fun(double *state, double dt, double *out_7514380099440619472);
void pose_F_fun(double *state, double dt, double *out_8168825780265645912);
void pose_h_4(double *state, double *unused, double *out_8652272607369950630);
void pose_H_4(double *state, double *unused, double *out_7970877321025946550);
void pose_h_10(double *state, double *unused, double *out_9075670553093884606);
void pose_H_10(double *state, double *unused, double *out_4573840938451450228);
void pose_h_13(double *state, double *unused, double *out_6456544963748931363);
void pose_H_13(double *state, double *unused, double *out_7263592927351272265);
void pose_h_14(double *state, double *unused, double *out_8577904112370749384);
void pose_H_14(double *state, double *unused, double *out_6512625896344120537);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}