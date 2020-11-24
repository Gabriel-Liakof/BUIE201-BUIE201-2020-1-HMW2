#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <random>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Times
{
	vector<long double> VectorConstructTime;
	vector<long double> SetConstructTime;
	vector<long double> FindSimpleWithRangeForLoopTime;
	vector<long double> FindBinarySearchTime;
	vector<long double> SetFindTime;

};
int FindSimpleWithRangeForLoop(vector<int> v, int ValueToFind)
{
	int i = 0;
	for (int x : v)
	{
		if (x == ValueToFind)
			return i;
		i++;
	}
	return -1;
}
int FindBinarySearch(vector<int>& v, int ValueToFind, int StartIndex, int EndIndex)
{
	if (EndIndex < StartIndex)
		return -1;

	int mid = (EndIndex + StartIndex) / 2;

	if (v[mid] == ValueToFind)
		return mid;

	if (v[mid] > ValueToFind)
		return FindBinarySearch(v, ValueToFind, StartIndex, mid - 1);

	//if (v[mid] < ValueToFind)
	return FindBinarySearch(v, ValueToFind, mid + 1, EndIndex);
}

void TestVectorSet(int sz,Times& MeanTimes)
{
    long double MeanTimeForVectorConstruct=0;
    for (int k = 0 ; k < 10 ; k++){
	auto start = chrono::system_clock::now();
    vector<int> largev;
	largev.reserve(sz);
    for (int i = 0 ; i < sz; i++)
	{
		largev.push_back(i);
	}

    auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	MeanTimeForVectorConstruct+= elapsed.count();
	}
	MeanTimeForVectorConstruct=MeanTimeForVectorConstruct/10;
	MeanTimes.VectorConstructTime.push_back(MeanTimeForVectorConstruct);


//////////////////////////////////////////////////////
    long double  meanTimeForSetConstruct=0;
    for (int k=0;k<10;k++){
	auto start = chrono::system_clock::now();
	set<int> IntSet;
	for (int i = 0; i < sz; i++)
	{
		IntSet.emplace(i);
	}

    auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	meanTimeForSetConstruct=meanTimeForSetConstruct+ elapsed.count();
	}   meanTimeForSetConstruct=meanTimeForSetConstruct/10;
	MeanTimes.SetConstructTime.push_back(meanTimeForSetConstruct);

   //////////////////////////////////////////////////////////
    long double meanTimeFindSimpleWithRangeForLoop=0;
    long double meanTimeFindBinarySearch=0;
    long double meanTimeSetFind=0;
     for (int k=0;k<10;k++){
        srand(time(NULL));
        int vf= rand()%(sz-1);
        vector<int> testvector;
        testvector.reserve(sz);
        for (int i = 0; i < sz; i++)
        {
            testvector.push_back(i);
        }
        set<int> TestSet;
        for (int i = 0; i < sz; i++)
	{
		TestSet.emplace(i);
	}

	auto start = chrono::system_clock::now();
	FindSimpleWithRangeForLoop(testvector,vf);
    auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	meanTimeFindSimpleWithRangeForLoop+= elapsed.count();

	start = chrono::system_clock::now();
	FindBinarySearch(testvector,vf,0,sz-1);
     end = std::chrono::system_clock::now();
	 elapsed = end - start;
	meanTimeFindBinarySearch += elapsed.count();

	start = chrono::system_clock::now();
    TestSet.find(vf);
     end = std::chrono::system_clock::now();
	 elapsed = end - start;
	meanTimeSetFind += elapsed.count();

	}
	meanTimeFindSimpleWithRangeForLoop=meanTimeFindSimpleWithRangeForLoop/10;
    MeanTimes.FindSimpleWithRangeForLoopTime.push_back(meanTimeFindSimpleWithRangeForLoop);

    meanTimeFindBinarySearch=meanTimeFindBinarySearch/10;
    MeanTimes.FindBinarySearchTime.push_back(meanTimeFindBinarySearch);

    meanTimeSetFind=meanTimeSetFind/10;
    MeanTimes.SetFindTime.push_back(meanTimeSetFind);



}

int main()
{   Times MeanTimes;
    vector<int> x={1000,10000,100000,1000000,10000000};
    for (int i: x){
        TestVectorSet(i,MeanTimes);
    }
    cout << "1000 | 10000 | 100000 | 1000000 | 10000000"<<endl;
    cout << "Vector construct  ";
	for (int i=0;i<5;i++){
        cout <<MeanTimes.VectorConstructTime[i]<< " | ";
	}
	cout<<endl;
	cout << "Set construct  ";
	for (int i=0;i<5;i++){
        cout<< MeanTimes.SetConstructTime[i]<< " | ";
	}
	cout<<endl;
	cout << "FindSimpleWithRangeForLoop  ";
	for (int i=0;i<5;i++){
        cout << MeanTimes.FindSimpleWithRangeForLoopTime[i]<< " | ";
	}
	cout<<endl;
	cout << "FindBinarySearch  ";
	for (int i=0;i<5;i++){
        cout<< MeanTimes.FindBinarySearchTime[i]<< " | ";
	}
	cout<<endl;
	cout << "Set find  ";
	for (int i=0;i<5;i++){
        cout << MeanTimes.SetFindTime[i]<< " | ";
	}
	cout<<endl;
	return 0;

}
