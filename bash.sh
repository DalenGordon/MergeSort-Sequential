#!/usr/bin/env bash
set -euo pipefail
make CXXFLAGS="-std=c++17 -Wall -O3 -DNDEBUG"

MIN=${1:-1}
MAX=${2:-7}

for ((p=MIN; p<=MAX; p++)); do
  n=$((10**p))
  out=$(./mergesort "$n")
  secs=$(printf "%s\n" "$out" | awk '/Elasped|Elapsed/ {for(i=1;i<=NF;i++) if ($i+0==$i) t=$i} END{if(t!="") print t}')
  echo "n=$n time=${secs:-NA}"
done

