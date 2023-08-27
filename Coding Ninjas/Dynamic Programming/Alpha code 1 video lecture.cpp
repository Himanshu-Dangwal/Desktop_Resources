//Alpha Code:::
//Iterative Approach without Dynamic Programming::
int num_codes(int *input,int size){
	int *output = new output[size+1];
	output[0]=1;
	output[1]=1;
	for(int i=2;i<=size;i++){
		output[i]=output[i-1];
		if((input[i-2]*10 + input[i-1])<=26){
			output[i]+=output[i-2];
		}
	}
	int ans=output[size];
	delete [] output;
	return ans;
}
/*
By coding ninjas::
int num_codes_i(int * input, int size) {
	int* output = new int[size + 1];
	output[0] = 1;
	output[1] = 1;

	for (int i = 2; i <= size; i++) {
		output[i] = output[i - 1];
		if (input[i-2] *10 + input[i - 1] <= 26) {
			output[i] += output[i - 2];
		}
	}
	int ans = output[size];
	delete [] output;
	return ans;
}
*/

//Recursive Approach with Dynamic Programming

int num_codes(int *input,int size,int *output){
	if(size==0 || size==1){
		return 1;
	}
	if(output[size]>0){
		return output[size];
	}
	int smallAns=num_codes(input,size-1,output);
	if(input[size-2]*10 + input[size-1] <=26){
		smallAns+=num_codes(input,size-2,output);
	}
	output[size]=smallAns;
	return smallAns;
}





