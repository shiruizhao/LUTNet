#pragma once


/***************************************
 **     Data type
 ***************************************/
#define AP_INT_MAX_W 9216
#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#ifndef bitwidth
#define bitwidth 1
#define PopCountWidth_val 24
#define PopCountIntWidth_val 16
#endif

#ifndef data_t
#define data_t ap_uint<bitwidth>
#define data_t_L1 ap_uint<L1_BW*L1_N>
#define data_t_L2 ap_uint<L2_BW*L2_N>
#define data_t_L3 ap_uint<L3_BW*L3_N>
#define data_t_L4 ap_uint<L4_BW*L4_N>
#define data_t_L5 ap_uint<L5_BW*L5_N>
#define data_t_out ap_uint<OutputWidth_val*L5_M>
#endif

/***************************************
 * Basic operations
 ***************************************/
// inlined
//inline int min(int a, int b) { return (a<b) ? a : b;}
//inline int max(int a, int b) { return (a>b) ? a : b;}
//inline data_t max_bn(data_t a, data_t b) { return (a>b) ? a : b;}

/********************************************
 **	Layer 1: FullyConnected
 ********************************************/
// fc parameters
#define L1_BW 8
#define L1_K 1 // kernel window size
#define L1_ST 1 //stride size
// input frame
#define L1_iR 1
#define L1_iC 1
#define L1_N 784
// output frame
#define L1_oR 1
#define L1_oC 1
#define L1_M 256
// tiling info
#define L1_TN 16
#define L1_TM 8

/********************************************
 **	Layer 2: FullyConnected
 ********************************************/
// fc parameters
#define L2_BW 2
#define L2_K 1 // kernel window size
#define L2_ST 1 //stride size
// input frame
#define L2_iR L1_oR
#define L2_iC L1_oC
#define L2_N L1_M
// output frame
#define L2_oR 1
#define L2_oC 1
#define L2_M 256
// tiling info
#define L2_TN 8
#define L2_TM 8

/********************************************
 **	Layer 3: FullyConnected
 ********************************************/
// fc parameters
#define L3_BW 2
#define L3_K 1 // kernel window size
#define L3_ST 1 //stride size
// input frame
#define L3_iR L2_oR
#define L3_iC L2_oC
#define L3_N L2_M
// output frame
#define L3_oR 1
#define L3_oC 1
#define L3_M 256
// tiling info
#define L3_TN 8
#define L3_TM 8


/********************************************
 **	Layer 4: FullyConnected
 ********************************************/
// convolution parameters
#define L4_BW 2
#define L4_K 1 // kernel window size
#define L4_ST 1 //stride size
// input frame
#define L4_iR L3_oR
#define L4_iC L3_oC
#define L4_N L3_M
// output frame
#define L4_oR 1
#define L4_oC 1
#define L4_M 256
// tiling info
#define L4_TN 8
#define L4_TM 8

/********************************************
 **	Layer 5: FullyConnected
 ********************************************/
// convolution parameters
#define L5_BW 2
#define L5_K 1 // kernel window size
#define L5_ST 1 //stride size
// input frame
#define L5_iR L4_oR
#define L5_iC L4_oC
#define L5_N L4_M
// output frame
#define L5_oR 1
#define L5_oC 1
#define L5_M 10
// tiling info
#define L5_TN 8
#define L5_TM 10

#define OutputWidth_val 24
