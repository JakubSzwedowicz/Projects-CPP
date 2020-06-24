#pragma once
#include<vector>
#include<string>
#include<deque>
#include<utility>

class Maze
{
	private:
		std::vector<std::string> m_map;		
		int m_rows;
		int m_columns;
	public:
		void Generate();
		void Print();
		std::vector<std::string>& getMap();
		void Push(int, int, std::deque<std::pair<int, int>>&, std::vector<std::vector<bool>>&);
		void Pop(std::deque<std::pair<int, int>>&);
};

