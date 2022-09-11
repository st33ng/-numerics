
#include <vector>

std::vector<float> Gaus(std::vector<std::vector<float>>& matrix,std::vector<float>& vec,bool flt=bool());
bool maxElementKolomn(std::vector<std::vector<float>>& matrix );
bool input(std::vector<std::vector<float>>& matrix,std::vector<float>& vec);

void H_input(std::vector<std::vector<float>>& matrix,std::vector<float>& vec);
void output(const std::vector<std::vector<float>> matrix) ;
void output(const std::vector<float> vec);
void built_in(std::vector<std::vector<float>>& matrix,std::vector<float>& vec);
void R_input();
void vector_transformation(std:: vector<float>& vec,float data);
void system_solutions(std::vector<std::vector<float>>& matrix,std::vector<float>& solution);
void upper_triangular_matrix(std::vector<std::vector<float>>& matrix);

std::pair<float,float> fault(std::vector<std::vector<float>> matrix,std::vector<float> solution,std::vector<float> vec_b);
std::vector<float> matrix_multiplication(std::vector<std::vector<float>>matrix,std::vector<float> vec);