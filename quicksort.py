def quicksort(array):

	n = len(array);
	
	if n <= 1:
		return array;
	
	result1, result2 = list(), list();
	
	for i in range(0, n):
		if array[i] <= array[n-1]:
			result1.append(array[i]);
		else:
			result2.append(array[i]);
	
	temp = quicksort(result1[:len(result1)-1]);
	
	temp.append(result1[len(result1)-1]);
	
	result2 = quicksort(result2);
	
	temp.extend(result2);
	
	return temp;

def main():
	numbers = [3, 7, 8, 5, 2, 1, 9, 5, 4];
	print(quicksort(numbers));

main();
