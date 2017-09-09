/**
 * doitgen.h: This file is part of the PolyBench 3.0 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#ifndef DOITGEN_H
# define DOITGEN_H

/* Default to STANDARD_DATASET. */
# if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET) && !defined(EXTRALARGE_DATASET)
#  define STANDARD_DATASET
# endif

/* Do not define anything if the user manually defines the size. */
# if !defined(NQ) && !defined(NR) && !defined(NP)
/* Define the possible dataset sizes. */
#  ifdef MINI_DATASET
#   define NQ 10
#   define NR 10
#   define NP 10
#  endif

#  ifdef SMALL_DATASET
#   define NQ 32
#   define NR 32
#   define NP 32
#  endif

#  ifdef STANDARD_DATASET /* Default if unspecified. */
#   define NQ 128
#   define NR 128
#   define NP 128
#  endif

#  ifdef LARGE_DATASET
#   define NQ 256
#   define NR 256
#   define NP 256
#  endif

#  ifdef EXTRALARGE_DATASET
#   define NQ 1000
#   define NR 1000
#   define NP 1000
#  endif
# endif /* !N */


# ifndef DATA_TYPE
#  define DATA_TYPE __attribute__((annotate("no_float"))) float
# endif
#  define DATA_PRINTF_MODIFIER "%0.12lf "


#endif /* !DOITGEN */
