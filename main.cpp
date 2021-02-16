#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono; 


using namespace std;

const string fb[15] = { "FizzBuzz", "", "", "Fizz", "", "Buzz", "Fizz", "", "", "Fizz", "Buzz", "", "Fizz", "", ""};

string fbLookup (int n){
	return fb[n];
}

string fizzbuzz (int n)
{
	int fizz = n % 3;
	int buzz = n % 5;
	string report = "";
	if (fizz==0){
		report += "Fizz";
	}
	if (buzz==0){
		report += "Buzz";
	}
	return report;
}

string calcbuzz[] (const int n ){
	string results[n];
	for(int x=0; x<=n; x++){
		results[x]=fizzbuzz(x);		
		//cout << x <<": "<< results[x] << "\n";
		// cout << to_string(x) <<": " << fizzbuzz(x) << "\n";
	}
	return results;
}

double timeit(string (*f)(int), n){
	return f(n)
}




const int iterations = 32000;
string results[iterations];
int main()
{	
	auto start = high_resolution_clock::now();


	int ff=0,bb=0,ffb=0,nn=0;
	for(int r=0; r<=iterations; r++){
		if (results[r] == ""){
			nn++;
		}
		else if (results[r] == "Fizz"){
			ff++;
		}
		else if (results[r] == "Buzz"){
			bb++;
		}
		else {
			ffb++;
		}
	}
	char counts [75];
	sprintf(counts, "Fizz:%d Buzz: %d FizzBuzz: %d Blanks:%d Total: %d\n", ff, bb, ffb, nn, ff + bb + ffb + nn) ;
	cout << counts;
	//cout << x <<": "<< fizzbuzz(x) << "\n";
	// cout << to_string(x) <<": " << fizzbuzz(x) << "\n";
	


	auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start); 

    std::chrono::duration<double, std::milli> duration = stop - start;
	char s[25];
	sprintf(s,"Duration: %d ms", duration);
	cout << s;
	return 0;
}
    