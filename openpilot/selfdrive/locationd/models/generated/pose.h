#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_287223720192222431);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7604442797155520121);
void pose_H_mod_fun(double *state, double *out_7308623482707293882);
void pose_f_fun(double *state, double dt, double *out_1494187582519062096);
void pose_F_fun(double *state, double dt, double *out_440712768552739407);
void pose_h_4(double *state, double *unused, double *out_3074332647112967580);
void pose_H_4(double *state, double *unused, double *out_5985602205963176999);
void pose_h_10(double *state, double *unused, double *out_8586129477608731499);
void pose_H_10(double *state, double *unused, double *out_7002946320442292);
void pose_h_13(double *state, double *unused, double *out_7994066762082839895);
void pose_H_13(double *state, double *unused, double *out_2773328380630844198);
void pose_h_14(double *state, double *unused, double *out_2538869907344583488);
void pose_H_14(double *state, double *unused, double *out_2022361349623692470);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}