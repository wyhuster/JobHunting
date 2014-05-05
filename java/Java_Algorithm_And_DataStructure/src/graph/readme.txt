This is a package which contains some method used in Graph.
	1.The Storage structure of graph.
	2...
	
	图在计算机中存储和表示必须要表示两个变量，第一个是图中的顶点，第二个是图中的边；
	顶点表示方式：
		1.数组变量，比如：String[] city = {"北京","上海","广州","深圳",};
		2.亦或是：
			class City
			{
				private String name;
				private float area;
				...
				public City(...)
				{
				}
				...
			}
			Object[] city = {new City(...),new City(...),...};
		3.对于一个拥有n个顶点的图，这n个顶点可以使用自然数0,1,2....来进行标注
	边的表示方式：
		1.边的数组：二维数组中的变量表示两个顶点之间存在着通路，edges.length:图中存在多少条通路，无向图一条边算两条通路
		int[][] edges = 
		{
			{0,1},{0,3},{0，5},
			{1,0},{1,2},{1,3},
			...
		};
		2.Edge对象表示：
		class Edge
		{
			int u;
			int v;
			public Edge(int u,int v)
			{
				this.u = u;
				this.v = v;
			}
		}
		可以用线性表ArrayList<Edge>来存储所有的边.
		3.邻接矩阵:adjecencyMatrix表示邻接矩阵，是一个n*n的二维数组，矩阵中的每一个元素为0或者1，如果顶点i到j存在通路，则adjecencyMatrix[i][j]=1;
		int[][] adjecencyMatrix = 
		{
			{0,0,1,0,0},	//Peter
			{0,0,1,0,0},	//Jane
			{0,0,0,0,1},	//Mark
			{0,0,0,0,1},	//Cindy
			{0,0,0,0,0},	//Wendy
		};
		4.邻接线性表：java.util.LinkedList[] neighbors = new java.util.LinkedList[12];
					 表中存储着与每个neighbors[i]的头结点相邻的节点.
	