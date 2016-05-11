t = gets.to_i
while t > 0 do
	pattern = gets.to_s
	i = 1
	ctr1 = 0
	ctr2 = 0
	exp = '+'
	str = pattern
	str.split("").each do |ch|
		# p ">>>>>>>>>> #{i} #{ch}"
		unless i >= str.length
			ctr1 = ctr1+1 unless exp==ch
			ctr2 = ctr2+1 if exp==ch
			exp = (exp=='+')? '-':'+'
		end
		i = i+ 1
	end
	ctr = (ctr1<=ctr2)? ctr1:ctr2

	# p ">>>>>> #{ctr}"

	i=1
	ctr1 = 0
	ctr2 = 0
	exp = '+'
	str = pattern.reverse 
	str.split("").each do |ch|
		# p ">>>>>>>>>> #{i} #{ch}"
		unless i == 1
			ctr1 = ctr1+1 unless exp==ch
			ctr2 = ctr2+1 if exp==ch
			exp = (exp=='+')? '-':'+'	
		end
		i = i +1
	end
	ctr_rev = (ctr1<=ctr2)? ctr1:ctr2
	# p ">>>>>> #{ctr_rev}"
	result = (ctr<=ctr_rev)? ctr:ctr_rev
	p result
	t = t-1
end
