#include "Maze.hpp"
#include <iostream>
#include <vector>	
#include <string>	// std::string
#include <random>	// for default_random_engine and uniform_int_distribution
#include <utility>	//  for std::pair
#include <deque> // for std::deque
#include <functional>

void Maze::Print()
{
	if(m_map.size() != 0)
		for(auto& k: m_map)
			std::cout << k << std::endl;
}
void Maze::Push(int a_rows, int a_columns, std::deque<std::pair<int, int>>& a_path, std::vector<std::vector<bool>>& a_map_info)
{
	a_path.push_back(std::make_pair(a_rows, a_columns));			
	a_map_info.at(a_path.back().first).at(a_path.back().second) = false;
}
void Maze::Pop(std::deque<std::pair<int, int>>& a_path)
{
	a_path.pop_back();
}
	
void Maze::Generate()
{
	// Generating the size of the maze
	std::cout << "How big should the maze be? [y*x]" << std::endl;
	std::cout << "y^ \n | \n | \n -----> \n     x" << std::endl;
	std::cout << "y: ";
	std::cin >> m_rows;
	std::cout << "x: ";
	std::cin >> m_columns;
	m_map.resize(m_rows);

	for(auto& k: m_map)
	{
		k.resize(m_columns);
		std::fill(k.begin(), k.end(), '#');
	}
	// Setting up the tools
	std::uniform_int_distribution<int> random_direction(-1, 1); // -1 - left, 1 - right, 3 - down, 4 - left 
	std::default_random_engine generator;

	auto dice_direction = std::bind(random_direction, generator);
	int direction;

	std::vector<std::vector<bool>> map_info(m_rows, std::vector<bool> (m_columns, true));
	std::deque<std::pair<int, int>> path;
	
	// Establishing the entrance
	std::uniform_int_distribution<int> distribution(0, m_columns-1);
	Push(0, distribution(generator), path, map_info);

	Print();
	
	while(path.back.first != m_rows-1)
	{
		
		direction = dice_direction();
		
}

int Maze::CountNeighbours(std::deque<std::pair<int, int>>& a_path)
{
	int neighbours = 0;	
}
