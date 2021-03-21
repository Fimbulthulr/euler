import std.stdio;
import std.conv;

import lexiographic_permutation;

int 
main(string[] args)
{
	ulong n = 1_000_000;
	ulong m = 10;
	if(args.length != 1 && args.length != 3)
	{
		stderr.writefln("Usage: %s [m n]", args[0]);
		return 1;
	}
	if(args.length == 3)
	{
		m = to!ulong(args[1]);
		n = to!ulong(args[2]);
	}
	int[] arr;
	arr.length = m;
	foreach(int i; 0..to!int(m))
	{
		arr[i] = i;
	}
		
	writefln("Unpermuted array is \n[%(%s, %)]\n", arr);
	lexiographic_permutation.lexiographic_permutation(arr, n);
	writefln("lexiographic permutation %s is\n[%(%s, %)]", n, arr);
	return 0;
}


