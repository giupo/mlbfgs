#include "mlbfgs.h"


void mexFunction(
  int nlhs, 
  mxArray *plhs[], 
  int nrhs, 
  const mxArray *prhs[]
) {
  const int N = 100;
  int i, ret = 0;
  lbfgsfloatval_t fx;
  lbfgsfloatval_t *x = lbfgs_malloc(N);
  lbfgs_parameter_t param;
  
  lbfgs_parameter_init(&param);
  /*param.linesearch = LBFGS_LINESEARCH_BACKTRACKING;*/

  /*
      Start the L-BFGS optimization; this will invoke the callback functions
      evaluate() and progress() when necessary.
  */
    
  ret = lbfgs(N, x, &fx, evaluate, progress, NULL, &param);
}
