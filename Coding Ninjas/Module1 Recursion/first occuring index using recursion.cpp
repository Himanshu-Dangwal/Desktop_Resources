int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int u;
    int k=-1;
	if(size==0)
        return -1;
    else{
    	u=firstIndex(input,size-1,x);
        if(input[size-1]==x)
            k=size-1;
    }
  	if(u!=-1){
        return u;
    }
	return k;
}
