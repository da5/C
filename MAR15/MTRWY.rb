require 'set'

edges = Set.new
adjacency = {}
unvisited = nil
vertex_component = {}

def get_idx(x,y,n,m)
	if x>n || y>m
		return -1
	elsif x<1 || y<1
		return -1
	else
		return ((x-1)*m+y)	
	end	
end

def max_connected_components(n,m, adjacency, vertex_component)
	max = 0
	unvisited = Set.new 1.step(n*m,1).to_a
	# vertex_component = {}
	component = 1
	while unvisited.any? do
		u = unvisited.take(1)
		# unvisited.delete(u.first)
		queue = Set.new u
		# queue << 
		size = 0
		
		while queue.any? do
			v = queue.take(1).first
			queue.delete(v)
			if unvisited.include? v
				unvisited.delete(v)
				vertex_component.merge!(v=>component)
				neighbours = adjacency[v]
				# unvisited.subtract(neighbours.to_a)
				# p "n->#{neighbours.inspect}"
				# p "q->#{queue.inspect}"
				queue = queue | neighbours
				size = size + 1
			end
		end
		max = size if max < size
		component = component + 1
		# p unvisited
	end
	max
end



t = gets.to_i
while t > 0 do
	score = 0
	n, m, q = gets.split.map(&:to_i)
	edges = Set.new
	adjacency = {} if adjacency.any?
	unvisited = nil
	vertex_component = {}

	i = 1
	while i<=n do
		j = 1
		while j<=m do
			cell = get_idx i,j,n,m
			right = get_idx i,j+1,n,m
			down = get_idx i+1,j,n,m
			up = get_idx i-1,j,n,m
			left = get_idx i,j-1,n,m
			
			neighbours = []
			neighbours << right unless right == -1
			neighbours << left unless left == -1
			neighbours << down unless down == -1
			neighbours << up unless up == -1

			# p "#{cell} -> #{neighbours}"

			edges << {:u=>cell, :v=>right} unless right == -1
			edges << {:u=>cell, :v=>down} unless down == -1
			adjacency.merge!(cell=>Set.new(neighbours))
			j = j+1
		end
		i = i+1
			
	end
	
	max =  max_connected_components(n,m,adjacency,vertex_component)

	# p "adjacency :: #{adjacency}"
	# p "edges :: #{edges.inspect}"
	# p "vertex_component :: #{vertex_component}"
	flag = 1

	while q > 0 do
		type,x,y,x2,y2  = gets.split.map(&:to_i)
		if type == 1
			cell = get_idx(x,y,n,m)
			right = get_idx(x,y+1,n,m)
			unless right == -1
				adjacency[cell].delete(right)
				adjacency[right].delete(cell)
			end
			flag = 0
		elsif type == 2
			cell = get_idx(x,y,n,m)
			down = get_idx(x+1,y,n,m)
			unless down == -1
				adjacency[cell].delete(down)
				adjacency[down].delete(cell)
			end
			flag = 0
		elsif type == 3
			if flag == 0
				vertex_component = {}
				max = max_connected_components(n,m,adjacency,vertex_component)
				flag = 1	
			end 
			score = score + 1 if vertex_component[get_idx(x,y,n,m)] == vertex_component[get_idx(x2,y2,n,m)]
			
		else 
			if flag == 0
				vertex_component = {}
				max = max_connected_components(n,m,adjacency,vertex_component)
				flag = 1	
			end
			score = score + max
			 
		end
		# p vertex_component
		# p "#{type}>>> #{score}"		
				


		q = q-1
	end

	p score	

	
	t = t-1
end
