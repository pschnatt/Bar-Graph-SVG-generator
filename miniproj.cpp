#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>

class BarGraphGenerator {
public:
    BarGraphGenerator(const std::string& fileName) : m_fileName(fileName) {}

    void generate(const std::string& bargraph_name, const std::vector<double>& values, const std::vector<std::string>& labels, const std::string& color) {
        // Open an file
        std::ofstream file;
        file.open(m_fileName);

        //Dimensions of the bars
        int maxValue = *std::max_element(values.begin(), values.end());
        int maxlabelsize = 0;
        for (auto label : labels){
            if (label.size() >= maxlabelsize){
                maxlabelsize == label.size();
            }
        }
        int width = 1200+(maxlabelsize*10),height = maxValue+200;
        int barWidth = ((width - 220) / values.size()) + (maxlabelsize*10) ;
        int barHeightUnit = (height - 200) / maxValue;

        //SVG header and graph dimensions
        file << "<svg width=\"" << width << "\" height=\"" << height+20  << "\" xmlns=\"http://www.w3.org/2000/svg\">\n"  <<  std::endl;

        //Bars and Labels
        for (int i = 0; i < values.size(); i++) {
            int barHeight = values[i] * barHeightUnit;
            int x = (110 + i * barWidth * 1.05) ;
            int y = (height - 100 - barHeight) - 2;
            file << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << barWidth << "\" height=\"" << barHeight << "\" style=\"fill:"<<color<<";stroke-width:3;stroke:rgb(255,255,255)\" />" << std::endl;
            file << "<text x=\"" << x + barWidth / 2 << "\" y=\"" << height - 75 << "\" font-size=\"12\" text-anchor=\"middle\">" << labels[i] << "</text>" << std::endl;
            file << "<text x=\"" << x + barWidth / 2 << "\" y=\"" << y - 5 << "\" font-size=\"12\" text-anchor=\"middle\">" << values[i] << "</text>" << std::endl;
        }

        //The axis
        file << "<line x1=\"100\" y1=\"100\" x2=\"100\" y2=\"" << height - 100 << "\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/>" << std::endl;
        file << "<line x1=\"100\" y1=\"" << height - 100 << "\" x2=\"" << width - 50 << "\" y2=\"" << height - 100 << "\" style=\"stroke:rgb(0,0,0);stroke-width:2\"/>" << std::endl;

        //Chart name
        file << "<text x=\"" << (width) / 2 << "\" y=\"" << height-10 << "\" font-size=\"30\" text-anchor=\"middle\">" << bargraph_name << "</text>" << std::endl;

        //SVG footer
        file << "</svg>" << std::endl;

        //Close the file
        file.close();
    }

private:
    std::string m_fileName;
};

std::vector<std::pair<std::string,double>> data_input(std::string filename){
  std::vector<std::pair<std::string,double>> output;
  std::vector<std::pair<std::string,double>> error;
  std::ifstream datain(filename);
  std::string line;

  if (datain.is_open()){
    while (std::getline(datain,line)){
      std::stringstream ss(line);
      std::stringstream cc(line);
      std::string word;
      int word_counter = 0;
      while(cc >> word){
        word_counter++;
      }
      //If the data = 2 (Name,Value), then it will be store in Vector
      if (word_counter == 2){
        std::string name,num_temp;
        cc.clear();
        ss >> name >> num_temp;
        double num = std::stod(num_temp);
        ss.clear();
        std::pair<std::string,double> pair_info = std::make_pair(name,num);
        output.push_back(pair_info);
      }
      //else will return null vector
      else{
        std::cout << "Number of data per line is not 2" << std::endl;
        return error;
      }
    }
    return output;
  }
}


int main(){
  std::vector<std::pair<std::string,double>> test1 = data_input("text.txt");
  std::vector<std::string> labels;
  std::vector<double> values;
  for (auto d : test1){
    labels.push_back(d.first.substr(0,5));
    values.push_back(d.second);
  }
  BarGraphGenerator graph("graph.svg");
  graph.generate("fruit sales",values,labels,"red");
  return 0;
}