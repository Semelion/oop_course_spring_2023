#include <iostream>
#include <string.h>
namespace geo2d{
	namespace orto{
		class quad {
		public:
			quad() = default;
			quad(const quad&) = default;
			~quad() = default;
		};
		class rect : quad{
		public:
			rect(const double x_start_in, const double y_start_in, const double x_end_in, const double y_end_in) {
			    x_start = x_start_in;
				x_end = x_end_in;
				y_start = y_start_in;
				y_end = y_end_in;
			}
			std::string get_value(){
				std::string out = "(" + std::to_string(x_start) + ", " + std::to_string(y_start) + ")\t(" + std::to_string(x_end) + ", " + std::to_string(y_end) + ")";
				return out;
			}
		private:
			double x_start = 0;
			double x_end = 0;
			double y_start = 0;
			double y_end = 0;
		};

		class square : quad{
		public:
			square(const double x_start_in, const double y_start_in, const double side_in) {
			    x_start = x_start_in;
				y_start = y_start_in;
				side = side_in;
			}
			std::string get_value(){
				std::string out = "(" + std::to_string(x_start) + ", " + std::to_string(y_start) + ")\tside: " + std::to_string(side);
				return out;
			}
		private:
			double x_start = 0;
			double y_start = 0;
			double side = 0;
		};
	}
}

int main(){
	geo2d::orto::rect test(1,1,2,2);
	geo2d::orto::square test2(1,1,3);
	std::cout << test.get_value() << "\n" << test2.get_value();
	return 0;
}
