#!/bin/bash

FORMAT='\033[33m%16s\033[39m%10s%10s\033[%sm%11s%11s\033[39m%16s\n'

check() {
        OPT="./$1_out"
        NOPT="./$1_out._not_opt"
        OPT_OUT="$OPT.output.csv"
        NOPT_OUT="$NOPT.output.csv"
        
        FIXT=$($OPT 2> $OPT_OUT)
        FLOT=$($NOPT 2> $NOPT_OUT)
        
        RESDIFF=($(./resultdiff.py "$OPT_OUT" "$NOPT_OUT"))
        
        OFLC_OPT=${RESDIFF[0]}
        OFLC_NOPT=${RESDIFF[1]}
        if [ "$OFLC_OPT" = "$OFLC_NOPT" ]; then
                OFLC='32'
        else
                OFLC='31'
        fi
        ERROR=${RESDIFF[2]}
        
        printf $FORMAT $1 $FIXT $FLOT $OFLC $OFLC_OPT $OFLC_NOPT $ERROR
}

printf $FORMAT '' 'fix T' 'flo T' '39' '# ofl fix' '# ofl flo' 'avg error'

if [ "$#" = "1" ]; then
        check $1;
        exit 0;
fi;
check "2mm"
check "3mm"
check "atax"
check "bicg"
check "cholesky"
check "doitgen"
check "gemm"
check "gemver"
check "gesummv"
check "mvt"
check "symm"
check "syr2k"
check "syrk"
check "trisolv"
check "trmm"

