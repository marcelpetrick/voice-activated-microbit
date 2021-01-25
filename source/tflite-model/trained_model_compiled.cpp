/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 25.01.2021 22:19:14

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/kernels/micro_ops.h"

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

namespace {

constexpr int kTensorArenaSize = 1568;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_ADD, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[31];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[15];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,624 } };
const TfArray<1, float> quant0_scale = { 1, { 0.04553883895277977, } };
const TfArray<1, int> quant0_zero = { 1, { -15 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { -1, 192, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const ALIGN(8) int8_t tensor_data2[8] = { -36, -89, 6, -127, -79, 18, -19, -112, };
const TfArray<1, int> tensor_dimension2 = { 1, { 8 } };
const TfArray<1, float> quant2_scale = { 1, { 0.011592506431043148, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(8) int8_t tensor_data3[16] = { -37, -37, 11, -67, -127, -61, -95, -93, -110, -46, 111, 54, -22, -47, 72, -27, };
const TfArray<1, int> tensor_dimension3 = { 1, { 16 } };
const TfArray<1, float> quant3_scale = { 1, { 0.0065226131118834019, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[3] = { -3508, 2366, -966, };
const TfArray<1, int> tensor_dimension4 = { 1, { 3 } };
const TfArray<1, float> quant4_scale = { 1, { 0.00018050252401735634, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int8_t tensor_data5[3*192] = { 
  -3, -50, -36, 7, -37, -13, 27, 78, -53, 42, 10, 20, -15, 33, 21, -45, -19, -11, 14, -22, -32, -1, 20, 21, -30, 23, 7, -5, 14, 18, 29, -57, -2, 5, -9, -4, -43, -59, 26, 27, -79, 28, 1, -18, -46, -9, 17, -25, -3, -25, 19, 5, -85, -26, 31, 49, -88, 52, -1, -43, 10, -45, -18, 1, 4, 17, 10, -50, -43, -43, 64, 24, -103, 51, -50, -8, 10, -43, -30, -27, 24, 3, 15, -38, -29, -37, 20, 41, 12, -28, -70, 0, 3, -7, -103, -15, -42, -16, -9, -72, -38, -57, 64, -79, -52, 27, -80, 43, -11, -23, -36, -38, -27, 13, 3, -52, -22, -50, 18, -51, -37, 8, -91, 7, -74, -6, -22, -67, -18, 4, -7, -49, -28, -18, 25, -92, 10, -67, -39, 0, -68, -8, -19, -23, -5, -26, -24, -43, -15, -51, 32, -104, 17, -21, -51, 40, -55, -14, -1, 0, -3, -25, -12, -22, 15, -30, 40, -81, 7, 24, -12, 20, -35, -127, 26, -11, -2, 12, -30, -3, -7, -14, 35, -20, -9, 37, 2, -40, -31, -47, 23, -6, 
  6, -16, 21, -5, 5, -24, -9, -10, 8, -13, -34, 19, -3, 22, -32, 8, 0, 6, 18, 18, -1, -14, -12, -2, -26, 8, -35, 27, 8, -22, -27, 15, 16, -6, 27, 0, -1, -9, -1, -3, -11, -2, -19, 6, -5, -24, -18, 26, 12, -42, 6, 16, -19, -27, -10, -16, -10, -9, -5, -27, 2, -38, -2, 4, 20, -5, 12, 5, -13, -3, -13, -11, -8, -14, 16, -5, 10, -25, -11, 28, 18, -44, 18, 11, -14, -40, -10, 0, -14, -9, 2, -14, 9, -38, 8, 14, 25, -26, 20, 14, -14, -1, 1, 18, -13, 1, -9, -17, 22, -23, -4, 27, 6, -15, -12, 17, -16, -4, 19, 1, -25, -10, -9, -12, 26, -17, 11, 16, 14, -29, 15, 16, -9, -4, -12, 25, -5, 16, 18, -13, 30, -18, -8, 27, 0, -35, 3, 4, -8, -6, -21, 6, -6, 8, 1, 6, 25, -35, -27, 33, 2, -9, 25, 5, -12, -16, -6, -3, -5, -4, -4, -3, 29, -24, -12, -1, 6, -23, 23, -7, 6, 15, -41, 27, -24, 2, -8, 21, 24, -18, -34, 11, 
  -16, 20, -4, 5, 25, 33, -8, -18, 15, -19, 12, -35, 12, -38, 9, -2, -33, 29, -13, -5, 28, 12, -8, -14, 12, -7, 1, -13, 2, 8, 12, 7, -23, 21, 1, -4, 15, 36, -15, -9, 9, -12, 21, 5, -9, 19, -1, -5, -27, 28, -21, -12, 9, 19, 1, -17, 22, 3, 2, 8, -12, 37, 13, -5, -9, 24, -13, 3, 28, 40, -19, -5, 19, -10, 18, -5, 1, 28, -6, -6, -24, 42, -16, -14, 33, 44, 11, 3, 8, 1, 23, 21, 2, 35, 31, -10, -19, 41, 4, -3, 42, 36, -5, 8, 42, 0, 4, 12, 7, 40, -2, 10, -25, 21, -15, 4, 32, 31, -21, 28, 10, 21, 19, 25, 4, 18, 4, -2, -5, 14, -13, -9, 17, 31, -20, 6, 14, 4, 22, 0, 9, 5, -7, -11, -20, 33, -6, 8, 12, 24, 13, 26, 31, 9, 6, 1, -10, 41, 12, -12, -24, 28, -8, -1, -24, 24, -4, 0, 16, -6, 18, 6, 13, 35, 32, 0, -1, -10, -22, -2, -2, -6, -5, -27, 18, -11, -10, -21, -13, 17, 4, -14, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 3,192 } };
const TfArray<1, float> quant5_scale = { 1, { 0.0094412779435515404, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int32_t tensor_data6[8] = { 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension6 = { 1, { 8 } };
const TfArray<8, float> quant6_scale = { 8, { 0.00026201488799415529, 0.0001545745471958071, 0.00024201109772548079, 0.00020868110004812479, 0.00019459024770185351, 0.00039969276986084878, 0.00024777144426479936, 0.00020064327691216022, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[8*1*3*13] = { 
  /* [0][0][][] */ -47,96,36,36,-3,13,19,13,3,5,-26,-8,5, 102,-109,-102,-28,-6,9,4,27,27,-8,5,-8,4, -127,21,62,10,-12,-47,-13,4,-3,-11,5,15,6, 
  /* [1][0][][] */ -20,-70,108,50,-48,-4,69,-83,40,16,97,-61,75, -43,-74,57,61,-69,7,93,-46,-35,52,63,-74,78, -59,-39,-9,86,18,-14,127,20,-62,25,68,-14,-8, 
  /* [2][0][][] */ -127,-34,32,3,-11,27,-18,32,-12,-1,2,6,0, -122,-20,-6,17,8,-58,70,-18,-12,-28,19,-70,32, -73,-58,-17,15,33,20,-29,18,-28,-19,31,44,8, 
  /* [3][0][][] */ 36,80,-2,0,65,-69,23,-58,4,-8,-1,-18,-6, 26,103,5,24,34,-30,50,-54,36,7,23,-1,-8, 15,127,-6,36,54,-26,34,1,43,-2,-33,-6,-8, 
  /* [4][0][][] */ 60,-23,-87,15,-8,21,38,16,10,-31,24,-24,-32, 72,1,-116,17,-18,29,34,15,-37,-25,-4,25,-12, 120,8,-127,27,-41,16,15,33,-17,-10,16,18,-20, 
  /* [5][0][][] */ -127,26,22,-14,-13,9,12,14,-23,-8,14,-13,7, -98,-23,10,23,-2,-23,-10,7,6,-15,-7,3,-13, 59,-26,-39,0,32,23,7,1,-9,-10,5,23,5, 
  /* [6][0][][] */ -35,10,-72,-40,-48,-22,27,20,3,12,13,11,7, -18,49,57,127,108,28,-10,-7,7,-16,22,57,15, -103,-51,10,-65,-30,-20,21,-6,-45,-15,5,-17,-4, 
  /* [7][0][][] */ -14,-28,127,-29,-49,-27,-43,-6,-16,-18,12,10,-26, 54,104,94,-66,-25,-16,-51,-20,-28,-22,18,-20,-11, 36,55,100,-75,-77,7,-11,8,-32,-10,1,15,-29, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 8,1,3,13 } };
const TfArray<8, float> quant7_scale = { 8, { 0.0057536573149263859, 0.0033943452872335911, 0.0053143887780606747, 0.0045824861153960228, 0.0042730611748993397, 0.0087769646197557449, 0.0054408819414675236, 0.00440598139539361, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int32_t tensor_data8[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension8 = { 1, { 16 } };
const TfArray<16, float> quant8_scale = { 16, { 0.00014579044363927096, 0.00019922151113860309, 0.00011290499969618395, 9.1576352133415639e-05, 0.0001123688998632133, 0.00017848983407020569, 0.000208957091672346, 0.000208885787287727, 0.00012849122867919505, 0.00017701290198601782, 0.00016953470185399055, 0.00013771149679087102, 0.0001210654154419899, 0.00018724375695455819, 0.00021877362451050431, 0.00010315648978576064, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(8) int8_t tensor_data9[16*1*3*8] = { 
  /* [0][0][][] */ 11,-19,-127,-14,15,-103,-15,-12, 32,6,-55,-30,3,-108,18,-1, 28,-8,34,-53,-3,71,66,-14, 
  /* [1][0][][] */ -3,-3,-85,26,52,-81,-36,29, -62,15,-127,-16,-38,-94,-67,-13, -17,9,-95,51,38,-92,-42,26, 
  /* [2][0][][] */ -32,58,-22,-41,2,73,-24,-15, 127,-69,-122,-6,51,-103,-44,27, -26,-30,1,-54,-55,-16,47,-24, 
  /* [3][0][][] */ -3,-44,-31,66,5,-19,-65,39, 75,-69,17,5,6,127,12,-41, 49,-114,32,-27,46,11,46,-72, 
  /* [4][0][][] */ -18,9,-27,-26,-52,-23,16,-27, -53,-39,-65,7,4,-68,-37,127, -50,-48,-69,87,4,-44,-55,28, 
  /* [5][0][][] */ -12,-21,-107,23,19,-48,-90,58, -47,3,-127,1,-10,-103,-111,-35, -22,-7,-71,-20,77,-62,-77,42, 
  /* [6][0][][] */ -15,-2,8,-34,-70,11,-9,6, -19,50,7,-127,-75,13,-4,-6, -17,87,7,-76,41,-10,-13,-82, 
  /* [7][0][][] */ -29,3,15,-109,-25,1,10,-26, -1,-18,-15,-36,76,9,8,-59, -7,-127,-84,-49,-10,-17,-15,-55, 
  /* [8][0][][] */ -40,-54,-76,25,-14,-47,26,77, -2,-9,-105,127,46,-32,-3,15, -93,12,-3,-74,28,1,-76,74, 
  /* [9][0][][] */ -18,-18,2,-101,44,3,2,-88, -33,94,8,-127,-11,-2,-1,-25, -29,-19,-32,-75,39,-44,-2,-9, 
  /* [10][0][][] */ -7,-19,25,-92,-80,-12,-18,-80, 3,-10,-1,-116,-98,-4,-8,-80, -5,-48,-5,-40,-127,8,3,-98, 
  /* [11][0][][] */ -34,-45,-127,-48,-53,-64,0,-31, 8,100,-66,-22,53,-98,-6,61, 13,-9,-46,-23,20,-58,6,18, 
  /* [12][0][][] */ 40,-49,-19,-19,5,127,35,9, 22,-70,-86,-15,40,-105,33,3, 44,-33,-61,-80,1,-29,-35,-11, 
  /* [13][0][][] */ -21,-24,-127,48,-5,-111,-67,-19, -20,0,-105,-3,39,-77,-57,-42, -45,16,-122,71,-8,-63,-22,-72, 
  /* [14][0][][] */ -19,37,6,0,-116,5,-3,-86, -19,22,-13,15,-127,6,-22,-82, -9,-5,26,-35,-116,-7,-10,-99, 
  /* [15][0][][] */ 127,-51,-46,-40,12,-65,-47,-4, 59,-63,-9,-90,-20,-36,117,1, 73,-102,-9,-84,-1,57,-90,-22, 
};
const TfArray<4, int> tensor_dimension9 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant9_scale = { 16, { 0.0049628335982561111, 0.0067816739901900291, 0.0038433845620602369, 0.0031173387542366982, 0.0038251352962106466, 0.0060759494081139565, 0.0071130814030766487, 0.0071106543764472008, 0.0043739532120525837, 0.0060256733559072018, 0.005771108902990818, 0.0046878191642463207, 0.0041211722418665886, 0.0063739409670233727, 0.0074472450651228428, 0.0035115368664264679, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(8) int32_t tensor_data10[4] = { 1, 1, 48, 13, };
const TfArray<1, int> tensor_dimension10 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data11[3] = { 1, 48, 8, };
const TfArray<1, int> tensor_dimension11 = { 1, { 3 } };
const ALIGN(8) int32_t tensor_data12[4] = { 1, 48, 1, 8, };
const TfArray<1, int> tensor_dimension12 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data13[4] = { 1, 1, 24, 8, };
const TfArray<1, int> tensor_dimension13 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data14[3] = { 1, 24, 16, };
const TfArray<1, int> tensor_dimension14 = { 1, { 3 } };
const ALIGN(8) int32_t tensor_data15[4] = { 1, 24, 1, 16, };
const TfArray<1, int> tensor_dimension15 = { 1, { 4 } };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,48,13 } };
const TfArray<1, float> quant16_scale = { 1, { 0.04553883895277977, } };
const TfArray<1, int> quant16_zero = { 1, { -15 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,48,8 } };
const TfArray<1, float> quant17_scale = { 1, { 0.070081643760204315, } };
const TfArray<1, int> quant17_zero = { 1, { 2 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<3, int> tensor_dimension18 = { 3, { 1,48,8 } };
const TfArray<1, float> quant18_scale = { 1, { 0.070081643760204315, } };
const TfArray<1, int> quant18_zero = { 1, { 2 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<3, int> tensor_dimension19 = { 3, { 1,48,8 } };
const TfArray<1, float> quant19_scale = { 1, { 0.029376450926065445, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<4, int> tensor_dimension20 = { 4, { 1,48,1,8 } };
const TfArray<1, float> quant20_scale = { 1, { 0.029376450926065445, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<4, int> tensor_dimension21 = { 4, { 1,24,1,8 } };
const TfArray<1, float> quant21_scale = { 1, { 0.029376450926065445, } };
const TfArray<1, int> quant21_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<4, int> tensor_dimension22 = { 4, { 1,1,24,8 } };
const TfArray<1, float> quant22_scale = { 1, { 0.029376450926065445, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfArray<4, int> tensor_dimension23 = { 4, { 1,1,24,16 } };
const TfArray<1, float> quant23_scale = { 1, { 0.099669866263866425, } };
const TfArray<1, int> quant23_zero = { 1, { 72 } };
const TfLiteAffineQuantization quant23 = { (TfLiteFloatArray*)&quant23_scale, (TfLiteIntArray*)&quant23_zero, 0 };
const TfArray<3, int> tensor_dimension24 = { 3, { 1,24,16 } };
const TfArray<1, float> quant24_scale = { 1, { 0.099669866263866425, } };
const TfArray<1, int> quant24_zero = { 1, { 72 } };
const TfLiteAffineQuantization quant24 = { (TfLiteFloatArray*)&quant24_scale, (TfLiteIntArray*)&quant24_zero, 0 };
const TfArray<3, int> tensor_dimension25 = { 3, { 1,24,16 } };
const TfArray<1, float> quant25_scale = { 1, { 0.019118441268801689, } };
const TfArray<1, int> quant25_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant25 = { (TfLiteFloatArray*)&quant25_scale, (TfLiteIntArray*)&quant25_zero, 0 };
const TfArray<4, int> tensor_dimension26 = { 4, { 1,24,1,16 } };
const TfArray<1, float> quant26_scale = { 1, { 0.019118441268801689, } };
const TfArray<1, int> quant26_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant26 = { (TfLiteFloatArray*)&quant26_scale, (TfLiteIntArray*)&quant26_zero, 0 };
const TfArray<4, int> tensor_dimension27 = { 4, { 1,12,1,16 } };
const TfArray<1, float> quant27_scale = { 1, { 0.019118441268801689, } };
const TfArray<1, int> quant27_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant27 = { (TfLiteFloatArray*)&quant27_scale, (TfLiteIntArray*)&quant27_zero, 0 };
const TfArray<2, int> tensor_dimension28 = { 2, { 1,192 } };
const TfArray<1, float> quant28_scale = { 1, { 0.019118441268801689, } };
const TfArray<1, int> quant28_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant28 = { (TfLiteFloatArray*)&quant28_scale, (TfLiteIntArray*)&quant28_zero, 0 };
const TfArray<2, int> tensor_dimension29 = { 2, { 1,3 } };
const TfArray<1, float> quant29_scale = { 1, { 0.095527641475200653, } };
const TfArray<1, int> quant29_zero = { 1, { 37 } };
const TfLiteAffineQuantization quant29 = { (TfLiteFloatArray*)&quant29_scale, (TfLiteIntArray*)&quant29_zero, 0 };
const TfArray<2, int> tensor_dimension30 = { 2, { 1,3 } };
const TfArray<1, float> quant30_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant30_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant30 = { (TfLiteFloatArray*)&quant30_scale, (TfLiteIntArray*)&quant30_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,10 } };
const TfArray<1, int> outputs0 = { 1, { 16 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 16,7,6 } };
const TfArray<1, int> outputs1 = { 1, { 17 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 17,11 } };
const TfArray<1, int> outputs2 = { 1, { 18 } };
const TfLiteAddParams opdata3 = { kTfLiteActRelu };
const TfArray<2, int> inputs3 = { 2, { 18,2 } };
const TfArray<1, int> outputs3 = { 1, { 19 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 19,12 } };
const TfArray<1, int> outputs4 = { 1, { 20 } };
const TfLitePoolParams opdata5 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs5 = { 1, { 20 } };
const TfArray<1, int> outputs5 = { 1, { 21 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 21,13 } };
const TfArray<1, int> outputs6 = { 1, { 22 } };
const TfLiteConvParams opdata7 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs7 = { 3, { 22,9,8 } };
const TfArray<1, int> outputs7 = { 1, { 23 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 23,14 } };
const TfArray<1, int> outputs8 = { 1, { 24 } };
const TfLiteAddParams opdata9 = { kTfLiteActRelu };
const TfArray<2, int> inputs9 = { 2, { 24,3 } };
const TfArray<1, int> outputs9 = { 1, { 25 } };
const TfLiteReshapeParams opdata10 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs10 = { 2, { 25,15 } };
const TfArray<1, int> outputs10 = { 1, { 26 } };
const TfLitePoolParams opdata11 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs11 = { 1, { 26 } };
const TfArray<1, int> outputs11 = { 1, { 27 } };
const TfLiteReshapeParams opdata12 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs12 = { 2, { 27,1 } };
const TfArray<1, int> outputs12 = { 1, { 28 } };
const TfLiteFullyConnectedParams opdata13 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs13 = { 3, { 28,5,4 } };
const TfArray<1, int> outputs13 = { 1, { 29 } };
const TfLiteSoftmaxParams opdata14 = { 1 };
const TfArray<1, int> inputs14 = { 1, { 29 } };
const TfArray<1, int> outputs14 = { 1, { 30 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 624, (TfLiteIntArray*)&tensor_dimension0, 624, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 12, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 576, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 312, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data12, (TfLiteIntArray*)&tensor_dimension12, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data13, (TfLiteIntArray*)&tensor_dimension13, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data14, (TfLiteIntArray*)&tensor_dimension14, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data15, (TfLiteIntArray*)&tensor_dimension15, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 624, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 624, (TfLiteIntArray*)&tensor_dimension17, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 384, (TfLiteIntArray*)&tensor_dimension19, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 384, (TfLiteIntArray*)&tensor_dimension21, 192, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 192, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 384, (TfLiteIntArray*)&tensor_dimension23, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant23))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension24, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant24))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 384, (TfLiteIntArray*)&tensor_dimension25, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant25))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension26, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant26))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 384, (TfLiteIntArray*)&tensor_dimension27, 192, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant27))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension28, 192, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant28))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 192, (TfLiteIntArray*)&tensor_dimension29, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant29))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension30, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant30))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_ADD, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_ADD, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs11, (TfLiteIntArray*)&outputs11, const_cast<void*>(static_cast<const void*>(&opdata11)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs12, (TfLiteIntArray*)&outputs12, const_cast<void*>(static_cast<const void*>(&opdata12)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs13, (TfLiteIntArray*)&outputs13, const_cast<void*>(static_cast<const void*>(&opdata13)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs14, (TfLiteIntArray*)&outputs14, const_cast<void*>(static_cast<const void*>(&opdata14)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static TfLiteStatus AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                                 size_t bytes, void** ptr) {
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    *ptr = malloc(bytes);
    if (*ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return kTfLiteError;
    }
    overflow_buffers.push_back(*ptr);
    return kTfLiteOk;
  }

  current_location -= bytes;

  *ptr = current_location;
  return kTfLiteOk;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  TfLiteStatus s = AllocatePersistentBuffer(ctx, b.bytes, &b.ptr);
  if (s != kTfLiteOk) {
    return s;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}
} // namespace

  TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 31;
  for(size_t i = 0; i < 31; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = *tflite::ops::micro::Register_RESHAPE();
  registrations[OP_CONV_2D] = *tflite::ops::micro::Register_CONV_2D();
  registrations[OP_ADD] = *tflite::ops::micro::Register_ADD();
  registrations[OP_MAX_POOL_2D] = *tflite::ops::micro::Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = *tflite::ops::micro::Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = *tflite::ops::micro::Register_SOFTMAX();

  for(size_t i = 0; i < 15; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 15; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  30, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 15; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
