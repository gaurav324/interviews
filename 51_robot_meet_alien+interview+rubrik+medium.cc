/*
This was an interesting problem about two X planet rovers. X planet is a straight line.

Two rovers land on mars using parachutes at same time. Now both would execute same program
at the same time. Only parameters available are rovers have camera to see whether
they can see another rover or can they see parachute.
*/

/*
SOLUTION: 1) Both rovers move 1 Step to Right and 2 to left and then 4R , 8L and so on, untill one of them
             reach a parachute and then it stops there. Then other one would find first rover.
					2) Second approach is that, each rover find moves slow in one direction. Later, one of them 
						 find parachute, it speeds up and catch the another rover.
	
@SpeedUp: How can we speed up? Thing is that at one time, one rover can move only one step.

>> Basically, we cannot speed up, but we certainly can slow down. 
>> Move L, L and then R, i.e. 2 steps L and then 1 step R.
>> After parachute is found, it runs only L.
*/
