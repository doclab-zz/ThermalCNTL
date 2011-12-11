/* Include files */

#include "blascompat32.h"
#include "ex_eml_block_call_stats_sfun.h"
#include "c1_ex_eml_block_call_stats.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ex_eml_block_call_stats_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[6] = { "len", "nargin", "nargout",
  "vals", "mean", "stdev" };

static const char * c1_b_debug_family_names[5] = { "nargin", "nargout", "array",
  "size", "mean" };

/* Function Declarations */
static void initialize_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void initialize_params_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void enable_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void disable_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void set_sim_state_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void sf_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void initSimStructsc1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance, const mxArray *c1_stdev, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static real_T c1_avg(SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance,
                     real_T c1_array[4], real_T c1_size);
static real_T c1_sum(SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance,
                     real_T c1_x[4]);
static void c1_eml_error(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_ex_eml_block_call_stats, const
  char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_ex_eml_block_call_stats = 0U;
}

static void initialize_params_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
}

static void enable_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_mean;
  real_T *c1_stdev;
  c1_stdev = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3));
  c1_hoistedGlobal = *c1_mean;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_stdev;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_ex_eml_block_call_stats;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_mean;
  real_T *c1_stdev;
  c1_stdev = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_mean = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "mean");
  *c1_stdev = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "stdev");
  chartInstance->c1_is_active_c1_ex_eml_block_call_stats = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_ex_eml_block_call_stats");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_ex_eml_block_call_stats(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
}

static void sf_c1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  real_T c1_vals[4];
  uint32_T c1_debug_family_var_map[6];
  real_T c1_len;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 2.0;
  real_T c1_mean;
  real_T c1_stdev;
  int32_T c1_i2;
  real_T c1_b_vals[4];
  int32_T c1_i3;
  real_T c1_c_vals[4];
  real_T c1_d0;
  int32_T c1_i4;
  real_T c1_a[4];
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_ak;
  real_T c1_y[4];
  int32_T c1_i5;
  real_T c1_b_y[4];
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_d_x;
  real_T c1_e_x;
  int32_T c1_i6;
  real_T c1_u[4];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i7;
  static char_T c1_cv0[2] = { '-', '+' };

  char_T c1_b_u[2];
  const mxArray *c1_e_y = NULL;
  real_T *c1_b_stdev;
  real_T *c1_b_mean;
  real_T (*c1_d_vals)[4];
  c1_b_stdev = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_d_vals = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_d_vals)[c1_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_mean, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_stdev, 2U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_vals[c1_i1] = (*c1_d_vals)[c1_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_len, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_vals, 3U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_mean, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_stdev, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_len = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    c1_b_vals[c1_i2] = c1_vals[c1_i2];
  }

  c1_mean = c1_avg(chartInstance, c1_b_vals, 4.0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    c1_c_vals[c1_i3] = c1_vals[c1_i3];
  }

  c1_d0 = c1_avg(chartInstance, c1_c_vals, 4.0);
  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    c1_a[c1_i4] = c1_vals[c1_i4] - c1_d0;
  }

  for (c1_k = 1.0; c1_k <= 4.0; c1_k++) {
    c1_b_k = c1_k;
    c1_ak = c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 4, 1, 0) - 1];
    c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 4, 1, 0) - 1] = muDoubleScalarPower(c1_ak, 2.0);
  }

  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_b_y[c1_i5] = c1_y[c1_i5];
  }

  c1_A = c1_sum(chartInstance, c1_b_y);
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_c_y = c1_c_x / 4.0;
  c1_d_x = c1_c_y;
  c1_stdev = c1_d_x;
  if (c1_stdev < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_e_x = c1_stdev;
  c1_stdev = c1_e_x;
  c1_stdev = muDoubleScalarSqrt(c1_stdev);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_u[c1_i6] = c1_vals[c1_i6];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4));
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    c1_b_u[c1_i7] = c1_cv0[c1_i7];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_call_debug("plot", 0U, 2U, 14, c1_d_y, 14, c1_e_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  *c1_b_mean = c1_mean;
  *c1_b_stdev = c1_stdev;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_ex_eml_block_call_statsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_ex_eml_block_call_stats
  (SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance, const mxArray *c1_stdev, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_stdev), &c1_thisId);
  sf_mex_destroy(&c1_stdev);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_stdev;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)
    chartInstanceVoid;
  c1_stdev = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_stdev), &c1_thisId);
  sf_mex_destroy(&c1_stdev);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i8;
  real_T c1_b_inData[4];
  int32_T c1_i9;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    c1_b_inData[c1_i8] = (*(real_T (*)[4])c1_inData)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    c1_u[c1_i9] = c1_b_inData[c1_i9];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv0[4];
  int32_T c1_i10;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
    c1_y[c1_i10] = c1_dv0[c1_i10];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_array;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i11;
  SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)
    chartInstanceVoid;
  c1_array = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_array), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_array);
  for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
    (*(real_T (*)[4])c1_outData)[c1_i11] = c1_y[c1_i11];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_ex_eml_block_call_stats_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c1_nameCaptureInfo;
}

static real_T c1_avg(SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance,
                     real_T c1_array[4], real_T c1_size)
{
  real_T c1_mean;
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i12;
  real_T c1_b_array[4];
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_y;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_c_x;
  real_T c1_c_y;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_array, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_size, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_mean, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    c1_b_array[c1_i12] = c1_array[c1_i12];
  }

  c1_A = c1_sum(chartInstance, c1_b_array);
  c1_B = c1_size;
  c1_x = c1_A;
  c1_y = c1_B;
  c1_b_x = c1_x;
  c1_b_y = c1_y;
  c1_c_x = c1_b_x;
  c1_c_y = c1_b_y;
  c1_mean = c1_c_x / c1_c_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  return c1_mean;
}

static real_T c1_sum(SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance,
                     real_T c1_x[4])
{
  real_T c1_y;
  int32_T c1_k;
  int32_T c1_b_k;
  c1_y = c1_x[0];
  for (c1_k = 2; c1_k < 5; c1_k++) {
    c1_b_k = c1_k;
    c1_y += c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 4, 1, 0) - 1];
  }

  return c1_y;
}

static void c1_eml_error(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance)
{
  int32_T c1_i13;
  static char_T c1_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  for (c1_i13 = 0; c1_i13 < 30; c1_i13++) {
    c1_u[c1_i13] = c1_varargin_1[c1_i13];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i14;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i14, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i14;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_ex_eml_block_call_stats, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_ex_eml_block_call_stats), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_ex_eml_block_call_stats);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_ex_eml_block_call_statsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_ex_eml_block_call_statsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_ex_eml_block_call_stats_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1623148159U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1014845198U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2840190554U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(902974028U);
}

mxArray *sf_c1_ex_eml_block_call_stats_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1068394390U);
    pr[1] = (double)(784883854U);
    pr[2] = (double)(246046234U);
    pr[3] = (double)(2119651237U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_ex_eml_block_call_stats(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"mean\",},{M[1],M[6],T\"stdev\",},{M[8],M[0],T\"is_active_c1_ex_eml_block_call_stats\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ex_eml_block_call_stats_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
    chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ex_eml_block_call_statsMachineNumber_,
           1,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ex_eml_block_call_statsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_ex_eml_block_call_statsMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_ex_eml_block_call_statsMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"vals");
          _SFD_SET_DATA_PROPS(1,2,0,1,"mean");
          _SFD_SET_DATA_PROPS(2,2,0,1,"stdev");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,267);
        _SFD_CV_INIT_EML_FCN(0,1,"avg",267,-1,322);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_mean;
          real_T *c1_stdev;
          real_T (*c1_vals)[4];
          c1_stdev = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_mean = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_vals = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_vals);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_mean);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_stdev);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_ex_eml_block_call_statsMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_ex_eml_block_call_stats(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ex_eml_block_call_statsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_ex_eml_block_call_stats
    ((SFc1_ex_eml_block_call_statsInstanceStruct*) chartInstanceVar);
  initialize_c1_ex_eml_block_call_stats
    ((SFc1_ex_eml_block_call_statsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ex_eml_block_call_stats(void *chartInstanceVar)
{
  enable_c1_ex_eml_block_call_stats((SFc1_ex_eml_block_call_statsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_ex_eml_block_call_stats(void *chartInstanceVar)
{
  disable_c1_ex_eml_block_call_stats((SFc1_ex_eml_block_call_statsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_ex_eml_block_call_stats(void *chartInstanceVar)
{
  sf_c1_ex_eml_block_call_stats((SFc1_ex_eml_block_call_statsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_ex_eml_block_call_stats
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ex_eml_block_call_stats
    ((SFc1_ex_eml_block_call_statsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ex_eml_block_call_stats();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_ex_eml_block_call_stats(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ex_eml_block_call_stats();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ex_eml_block_call_stats
    ((SFc1_ex_eml_block_call_statsInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_ex_eml_block_call_stats
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ex_eml_block_call_stats(S);
}

static void sf_opaque_set_sim_state_c1_ex_eml_block_call_stats(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_ex_eml_block_call_stats(S, st);
}

static void sf_opaque_terminate_c1_ex_eml_block_call_stats(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ex_eml_block_call_statsInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_ex_eml_block_call_stats
      ((SFc1_ex_eml_block_call_statsInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_ex_eml_block_call_stats
    ((SFc1_ex_eml_block_call_statsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ex_eml_block_call_stats(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_ex_eml_block_call_stats
      ((SFc1_ex_eml_block_call_statsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ex_eml_block_call_stats(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ex_eml_block_call_stats",
      "ex_eml_block_call_stats",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ex_eml_block_call_stats",
                "ex_eml_block_call_stats",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "ex_eml_block_call_stats","ex_eml_block_call_stats",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ex_eml_block_call_stats",
        "ex_eml_block_call_stats",1,1);
      sf_mark_chart_reusable_outputs(S,"ex_eml_block_call_stats",
        "ex_eml_block_call_stats",1,2);
    }

    sf_set_rtw_dwork_info(S,"ex_eml_block_call_stats","ex_eml_block_call_stats",
                          1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1452201117U));
  ssSetChecksum1(S,(1259313572U));
  ssSetChecksum2(S,(28806111U));
  ssSetChecksum3(S,(766175992U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_ex_eml_block_call_stats(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ex_eml_block_call_stats",
      "ex_eml_block_call_stats",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_ex_eml_block_call_stats(SimStruct *S)
{
  SFc1_ex_eml_block_call_statsInstanceStruct *chartInstance;
  chartInstance = (SFc1_ex_eml_block_call_statsInstanceStruct *)malloc(sizeof
    (SFc1_ex_eml_block_call_statsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ex_eml_block_call_statsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ex_eml_block_call_stats;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_ex_eml_block_call_stats_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ex_eml_block_call_stats(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ex_eml_block_call_stats(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ex_eml_block_call_stats(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ex_eml_block_call_stats_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
