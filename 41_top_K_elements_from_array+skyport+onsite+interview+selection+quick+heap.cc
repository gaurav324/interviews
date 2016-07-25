// There are various variants to this problem.
//
// Question: (that was asked in the interview)
// Given filename,bytes_read kind of log, we have to report top 5 files from maximum bytes have been read.
// Also, as the log keeps on getting new entries, top 5 question could be asked over and over again.
//
// SOLUTION:
// As data keep on getting coming, we keep on aggregating stats for each file.
// Then, whenever, top K have to be reported, we keep a min heap and report back the top K in the end.
// For getting top K, time complexity is nlog(k), which is quite good I think.
//
// IN GENERAL, we discuss selection algorithms:
// --------------------------------------------
// Sorting Algorithm could be used to do the selection. Sort all the numbers and those could
// then be used for selecting how so many. Time complexity is nlog(n).
// 
// We could also do some partial sorting. So that we can get back top K elements.
// One such partial sorting algorithm is QuickSelect.
// QuickSelect: 1) Partition such that elements on left are smaller than elements on right.
// 							2) And then keep on recursively doing in only one partition.
//       O(n) for selecting in average case.
//       How? Lets say in the average case, we divide the input into two parts.
//       Then elements to be looked at would be: n + n/2 + n/4 + n/8 + .. = 2n.
//
// What is the problem with selection based algorithm?
// > Selection algorithm tells us that Kth smallest element. Then we have to find other K-1 smaller elements.
//   QuickSelect would actually give those K-1 elements too. But then problem is we would have to sort K-1 elements, if we want order.
//   In this problem we do care about the order of the pending elements. Therefore, another kLog(k) is required.
//
// To summarize, if K is generally very small, then we are ok with heap based solution.
// As all we need to do is iterate over and keep checking with min heap.
// However, if K becomes very large, Nlog(k) becomes large, however with a quick select we would be doing, N + Klog(K).
// 
