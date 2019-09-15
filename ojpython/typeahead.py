class TypeAhead(object):
	def __init__(self):
		self.root = {}
		pass	
	
	def add(self,txt):
		curr_node = self.root
		for idx, c in enumerate(txt):			
			if c not in curr_node:
				dct = {}
				curr_node[c] = dct
				curr_node = dct
			else:
				curr_node = curr_node[c]
		
		curr_node['*'] = {} # it is the end flag
		pass


	def get_all_childs(self, curr_node,prefix):
		ret_list = []
		comb = ''
		self.dfs(curr_node, ret_list, comb,prefix)
		return ret_list


	def dfs(self, node, ret_list, comb, prefix):		
		if len(node) == 0:			
			return

		for key,value in node.items():
			#value is dct
			if key=='*':
				ret_list.append(prefix + comb)
			else:
				comb+=key
				self.dfs(value, ret_list, comb,prefix)				
				comb=comb[:-1]

	def get(self,txt):		
		curr_node = self.root
		for idx, c in enumerate(txt):
			if c not in curr_node:
				return []
			else:
				curr_node = curr_node[c]
		#st = [txt] if '*' in curr_node  else []
		return self.get_all_childs(curr_node,txt)


obj = TypeAhead()
obj.add('abc')
obj.add('bar')
obj.add('bark')
obj.add('barko')
print(obj.get('bark'))
