"""
Given a array of length N and another integer K.
We need to design a service, getMaxInRange(int i), it returns maximum in the range arr[i, i+k-1].

SOLUTION:
  1) We don't want to search everytime in the i, i+K range.
  2) We probably want to pre-process the array first and save the solutuon.

"""

int preProcess() {
	std::vector<int> ans;

	std::set<int> last_k_seen;
	for (int j=0; j < K; ++j) {
		last_k_seen.insert(arr[j]);
	}

	
	for (int j=0; j < arr.size(); ++j) {
		auto first = last_k_seen.first();
		ans.push_back(first);
		last_k_seen.remove_first();
		if (j+k < arr.size()) {
			last_k_seen.insert(arr[j+k]);
		}
	}

	return ans;
}

int getMaxInRange(int i) {
	return ans[i];
}
