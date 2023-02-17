**Aim**:

Implement a server using LibHTTP and study the behaviour of Throughput (Requests served/second) with the change in the number of concurrent requests using load testing tool like Apache Benchmark.
 
**Steps to run the server:**

1. Copy the unzipped directory "22m2109-cs695-a1" to libhttp-1.8/examples/ and cd to the   directory (cd libhttp-1.8/examples/22m2109-cs695-a1/)
2. Run the "make" command
3. ./cflask <port> <number of threads> e.g. ./cflask 8080 10

**The list of URLs supported for testing:**

1. / : returns "Hello World !"
2. /square?num=4 : returns square of 4(=16) and "1" if no query parameter is provided
3. /cube?num=4 : returns cube of 4(=64) and "1" if no query parameter is provided
4. /helloworld?str=Anubhav : returns "Hello,Anubhav" and "Hello" if no query param given
5. /pingpong?str=cs695 : returns only "cs695" and "PingPong" if no query param given
6. /arithmetic/fibonacci?num=5: returns 5th fibonacci number in the series,i.e. 3
7. /arithmetic/prime?num=7: returns True since 7 is a prime

**URL apart from those listed above has been handled too and will generate an URL Not Found message to the user**

**Load Testing by Apache Benchmark**

Total number of requests is fixed at 100000.
Concurrent number of requests was tested against 5,10,15,20,30,50,100.

Command: ab -n 100000 -c <values>  <URL>

The following load testing was automated using bash script in /directory/plots/plot.sh and graph was plotted using pyplot using a python script in /directory/plots/plot.py

The bash script dumps the throughput data into a csv file which is consumed by the python script


**Graph Plotting**

Graph plotted : Throughput vs Concurrent Users for 3 different thread pool size 10,20 and 30 and the same is repeated for 3 different function URLS.

load1*.csv -> data to plot graph for function URL /helloworld?str=Anubhav
load2*.csv -> data to plot graph for function URL /square?num=3
load3*.csv -> data to plot graph for function URL /arithmetic/fibonacci?num=5

plot*.png -> Contains the graph as a .png file

**Observations**

Throughput will increase initially until a certain threshold and then flatten out.
Avg RTT will remain constant for some time and then will tend to increse exponentially.

**Outputs**

The results of the URL execution is present in /directory/outputs/results.odt

**Directory**

Main directory
|-> /outputs 
        |-->results.odt
|
|-> /plots
|       |       
|       |-> load11.csv,load12.csv,load13.csv,load21.csv,load22.csv,load23.csv,load31.csv       load32.csv,load33.csv,plot.py,plot.sh,plot.png,plot2.png,plot3.png
|
|->functions.h
|->functions.c
|->functionslist.h
|->cflask.c
|->MakeFile
|->Readme.md