# Benchmark Programs

These are the programs that can be run for cache profiling / fault injection (soon) / pmu counter tests.

/common: files used for setting up the board and configuring the caches

## Micro Benchmarks

In development.
Each of these is intended to stress a different behavior of the cache or test setup.

/micro_evict: load 2x words (where x is the number of ways) from colliding addresses to force evictions
 
/micro_prefetch: load data by accessing every 2n word in a range, and then access every 2n+1 word (which may have been pre-fetched)

/micro_time: DrSEUs with Simics uses discrete checkpoints to inject faults, whereas our JTAG based approach can inject at any point.
This benchmark should expose how this can lead to differing results.

## MiBench

/mi_adpcm:

/mi_aes:

/mi_basicmath:

/mi_bitcount:

/mi_crc:

/mi_fft:

/mi_gsm:

/mi_qsort:

/mi_qsort_test:

/mi_susan:

## Quinn Benchmarks

/q_aes:

/q_cache:

/q_matrix:

/q_qsort:


## Others

/chielle:

/lzo:

/tambara:

## Test

/fib_rec:

/fib_short:

/test_binary_out:

/test_loop:
