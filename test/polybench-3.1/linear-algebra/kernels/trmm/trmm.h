/**
 * trmm.h: This file is part of the PolyBench 3.0 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#ifndef TRMM_H
# define TRMM_H

/* Default to STANDARD_DATASET. */
# if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET) && !defined(EXTRALARGE_DATASET)
#  define STANDARD_DATASET
# endif

/* Do not define anything if the user manually defines the size. */
# if !defined(NI)
/* Define the possible dataset sizes. */
#  ifdef MINI_DATASET
#   define NI 32
#  endif

#  ifdef SMALL_DATASET
#   define NI 128
#  endif

#  ifdef STANDARD_DATASET /* Default if unspecified. */
#   define NI 1024
#  endif

#  ifdef LARGE_DATASET
#   define NI 2000
#  endif

#  ifdef EXTRALARGE_DATASET
#   define NI 4000
#  endif
# endif /* !N */


# ifndef DATA_TYPE
#  define DATA_TYPE __attribute__((annotate("no_float"))) float
# endif
#  define DATA_PRINTF_MODIFIER "%0.16lf "


#endif /* !TRMM */
