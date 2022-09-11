//
// Includes
//

#include <iostream>
#include <cmath>
#include <vector>


//
//Addones
//

void app();

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

int main() {

    std::vector<std::vector<float>> matrix;
    std::vector<float> vec;

    Gaus(matrix,vec);


}
std::vector<float> Gaus( std::vector<std::vector<float>>& matrix,std::vector<float>& vec,bool flt ){

    if(matrix.empty())
        if(!input(matrix,vec))
        return vec;

    std::vector<std::vector<float>> tmp_matrix(matrix);

    for(int i=0;i<vec.size();i++)
        tmp_matrix[i].push_back(vec[i]);

    if(!flt)
        output(tmp_matrix);
    if(tmp_matrix.size()>1) {
        if (!maxElementKolomn(tmp_matrix)) {
            std::cout << "solutions do not exist ";
            return vec;
        }
    }
    else
        std::cout << "error: matrix size <= 1 ";


    upper_triangular_matrix(tmp_matrix);
    std::vector<float> solution;

    if(!flt) {
        std::cout << "upper_triangular_matrix___  \n ";
        output(tmp_matrix);
    }
    system_solutions(tmp_matrix,solution);
    std::pair<float,float> error;
    if(!flt) {
        error = fault(matrix, solution, vec);
        std::cout<<"absolute fault: "<<error.first<<"\n relative fault: "<<error.second;
    }


    return solution;
}
bool maxElementKolomn(std::vector<std::vector<float>>& matrix ){

    float tmp_max=matrix[0][0];
    int index=0;
    bool Swap=false;

    std::cout<<std::endl;

    for(int kolvo = 0,j=0;kolvo<matrix.size()-1 ;kolvo++ ) {
        for (int i = kolvo; i < matrix.size(); i++) {
            if(fabs(tmp_max)<fabs(matrix[i][j])) {
                tmp_max = matrix[i][j];
                index=i;
                Swap=true;
            }
            if (i == matrix.size() - 1)
                j++;
        }

        if(tmp_max==0)
            return false;
        else if(Swap==true) {
            Swap=false;
            tmp_max = matrix[kolvo][kolvo];
            tmp_max = matrix[kolvo+1][j];
            std::swap(matrix[kolvo],matrix[index]);
        }
    }
    return true;
}
bool input(std::vector<std::vector<float>>& matrix,std::vector<float>& vec){
    int info_type=0;
    std::cout << "type of input \n" << "Hand(1)" << " " << "Random(2)??" << "built-in(3)" << " " << "Another - end "<< " choise: "  ;
    std::cin >> info_type;
// ToDO:: R_input,built-in

    switch (info_type){
        case 1:
            H_input(matrix,vec);
            break;
        case 2:
            //R_input();
            break;
        case 3:
            built_in(matrix,vec);
            break;
        default:
            std::cout<<"default: unknown type";
            return false;
    }
    return true;
}

void system_solutions(std::vector<std::vector<float>>& matrix,std::vector<float>& solution){


    float r1=0;
    float r2=0;
    float summ=0;

    for(int j=matrix.size()-1,kolvo=1;j>=0;j--,kolvo++){
        summ=0;
        for(int i=matrix.size()-1,ke=solution.size()-1;i>matrix.size()-kolvo;i--,ke--){
            matrix[j][i]*=solution[ke];
        }

        for(int f=matrix.size()-1;f>matrix.size()-kolvo;f--){
            summ+=matrix[j][f];
        }
        r1=matrix[matrix.size()-kolvo][matrix[j].size()-1]-summ;
        r2= matrix[matrix.size()-kolvo][matrix[j].size()-1-kolvo];
        solution.insert(solution.begin(), (matrix[matrix.size()-kolvo][matrix[j].size()-1]-summ) / matrix[matrix.size()-kolvo][matrix[j].size()-1-kolvo]);



    }

}
void H_input(std::vector<std::vector<float>>& matrix,std::vector<float>& vec){
    int size_of_matrix=0;

    std::cout<<"Insert matrix size:  ";
    std::cin>>size_of_matrix;
    matrix.resize(size_of_matrix);


    for(int i=0;i<size_of_matrix;i++){
        matrix[i].resize(size_of_matrix);
        for(int j=0;j<size_of_matrix;j++){
            std::cin >> matrix[i][j];
            //Todo :: проверка типов .
        }
    }

    std::cout<<"Vec B: ";
    vec.resize(size_of_matrix);
    for(int i=0;i<size_of_matrix;i++){
        std::cin>>vec[i];
    }

}
void output(const std::vector<std::vector<float>> matrix ) {
    std::cout<<std::endl;
    for(int i=0;i<matrix.size();i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout<<std::endl;
    }

}
void built_in(std::vector<std::vector<float>>& matrix,std::vector<float>& vec){

    matrix={{2,3,-1},{1,-1,6},{6,-2,1}};
    vec={7,14,11};
  //  matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

}
void R_input(){
    int size_of_matrix=0;

    std::cout<<"Insert matrix size:  ";
    std::cin>>size_of_matrix;

}
void vector_transformation(std:: vector<float>& vec,float data){
    for(int i=0;i<vec.size();i++)
        vec[i]*=data;
}
void upper_triangular_matrix(std::vector<std::vector<float>>& matrix){
    float tmp=matrix[0][0];

    for(int i=0;i<matrix[0].size();i++)
        matrix[0][i]/=tmp;

    std:: vector<float> tmp_vector;
    tmp_vector.reserve(matrix.size());


    for(int k=1;k<matrix.size();k++) {
        for (int i = k; i < matrix.size(); i++) {
            tmp_vector = matrix[k-1];

            vector_transformation(tmp_vector, matrix[i][k-1]);
            for (int j = k-1; j < matrix[i].size(); j++) {
                matrix[i][j] -= tmp_vector[j];
            }

            tmp = matrix[i][i];

            for (int j = k-1; j < matrix[0].size(); j++)
                matrix[i][j] /= tmp;

        }
    }

    return;
}
void output(const std::vector<float> vec){
    for(int i=0; i<vec.size();i++){
        std::cout<<vec[i]<<" ";
    }
}
std::pair<float,float> fault(std::vector<std::vector<float>> matrix,std::vector<float> solution,std::vector<float> vec_b){

    std::vector<float> tmp_solution= matrix_multiplication(matrix,solution);

    for(int i=0;i<solution.size();i++){
        tmp_solution[i]-=vec_b[i];
    }

    tmp_solution=Gaus(matrix,tmp_solution,true);
    float absolute_fault=0.0f;
    float max2=0.0f;
    for(int i=0;i<tmp_solution.size();i++){
        if(absolute_fault<fabs(tmp_solution[i]))
            absolute_fault=fabs(tmp_solution[i]);
        if(max2<fabs(solution[i]))
            max2=fabs(solution[i]);
    }

    float relative_fault = (absolute_fault/max2)* 100;

    std::pair<float,float> error;
    error.first=absolute_fault;
    error.second=relative_fault;

    return error;
}
std::vector<float> matrix_multiplication(std::vector<std::vector<float>> matrix,std::vector<float> vec){

    std::vector<float> solution;
    solution.resize(vec.size());

    for (int i = 0; i < matrix.size(); i++){
        for (int k = 0; k < vec.size(); k++)
            solution[i] += matrix[i][k] * vec[k];
    }
    return solution;
}

//proov
//
// Info:: Вектор невязки - оценка погрешности
//