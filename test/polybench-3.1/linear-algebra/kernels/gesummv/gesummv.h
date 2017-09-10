/**
 * gesummv.h: This file is part of the PolyBench 3.0 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#ifndef GESUMMV_H
# define GESUMMV_H

/* Default to STANDARD_DATASET. */
# if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET) && !defined(EXTRALARGE_DATASET)
#  define STANDARD_DATASET
# endif

/* Do not define anything if the user manually defines the size. */
# ifndef N
/* Define the possible dataset sizes. */
#  ifdef MINI_DATASET
#   define N 32
#  endif

#  ifdef SMALL_DATASET
#   define N 500
#  endif

#  ifdef STANDARD_DATASET /* Default if unspecified. */
#   define N 4000
#  endif

#  ifdef LARGE_DATASET
#   define N 8000
#  endif

#  ifdef EXTRALARGE_DATASET
#   define N 100000
#  endif
# endif /* !N */


# ifndef DATA_TYPE
#  define DATA_TYPE __attribute__((annotate("no_float"))) float
# endif
#  define DATA_PRINTF_MODIFIER "%0.16lf "


#endif /* !GESUMMV */
