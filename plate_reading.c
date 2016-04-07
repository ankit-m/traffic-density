#include <stdio.h>
#include <time.h>

struct vehicles{
	float weight;
	clock_t startTime;
} vehicles[15];

//conversion
float findWeight(float value){
	float weight = value*5/1023;
	return weight;
}

//From pressure plate 1 - just stores weight and initial time
void table(int index,float reading){
	clock_t t;
	t = clock();
	vehicles[index].starTime = t;
	vehicles[index].weight = findWeight(reading);
}

//Returns the total time spent in the area as a double
double compare(float value){
	clock_t end, begin;
	end = clock();
	double time_spent;
	float we = findWeight(value);
	int i, index=0;
	for (i=0; i<15; i++){
		if(vehicles[i].weight == we){
			begin = vehicles[i].startTime;
			vehicles[i] = EmptyStruct;
			break;
		}
	}

	time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
	return time_spent;
}

int main(void) {
	clock_t begin, end;
	double time_spent;
	int counter = 0;
	begin = clock();

	/**ADD LOOP HERE. WHILE WE KEEP GETTING READINGS FROM FIRST PLATE. counter is the id to the structure
	so must be unique. check for emptystructs as well (once removed)*/

	table(counter, reading);
	counter++;
	/**seperate for 1st plate and 2nd plate -- for the 2nd plate, use the compare function.
	it will return the time taken by that vehicle in the zone*/

	//end loop

	end = clock();
	time_spent = (double)(end-begin)/CLOCKS_PER_SEC;	//total time in area
	return 0;
}
