#include "cctk.h"
#include "cctk_Parameters.h"
#include "cctk_Arguments.h"
#include "util_Table.h"
#include <cassert>
#include <cmath>
#include <cstdlib>

extern "C" void VI_GRMHDX_InitializeIntegralCounterToZero(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_VI_GRMHDX_InitializeIntegralCounterToZero;
  DECLARE_CCTK_PARAMETERS;

  // Init Counter
  *IntegralCounter = 0;

  // Init CoM Coord Holders
  *comx = 0;
  *comy = 0;
  *comz = 0;

  // Init Array that Holds Results
  for (int ii = 0; ii < 101; ii++) {
    for (int jj = 0; jj < 4; jj++) {
      const int arridx = 4 * ii + jj;
      VolIntegral[arridx] = 0.0;
    }
  }

  if (verbose == 2)
    printf("VolumeIntegrals_GRMHDX: Just set IntegralCounter to %d\n",
           *IntegralCounter);
}

extern "C" void VI_GRMHDX_InitializeIntegralCounter(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_VI_GRMHDX_InitializeIntegralCounter;
  DECLARE_CCTK_PARAMETERS;

  if (cctk_iteration % VolIntegral_out_every == 0) {
    *IntegralCounter = NumIntegrals;
    if (verbose == 2)
      printf("VolumeIntegrals_GRMHDX: Just set IntegralCounter to %d == "
             "NumIntegrals\n",
             *IntegralCounter);
  }
}

extern "C" void VI_GRMHDX_DecrementIntegralCounter(CCTK_ARGUMENTS) {
  DECLARE_CCTK_ARGUMENTSX_VI_GRMHDX_DecrementIntegralCounter;
  DECLARE_CCTK_PARAMETERS;

  (*IntegralCounter)--;
  if (verbose == 2)
    printf("VolumeIntegrals_GRMHDX: Just decremented IntegralCounter to %d\n",
           *IntegralCounter);
}
