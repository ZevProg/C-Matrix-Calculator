# include "MyMatrix.h"

int main() {
    // Test 1
    cout << "First test:\n" << endl;
    cout << "Enter values for 4x3 matrix A" << endl;
    MyMatrix A(4, 3);
    cin >> A;
    MyMatrix B;
    B[2][2] = 3;
    cout << "Matrix B is:" << endl << B << endl;
    cout << "Enter values for 3x3 matrix C" << endl;
    MyMatrix C(3, 3);
    cin >> C;
    cout << "Enter values for 3x3 matrix D" << endl;
    MyMatrix D(3, 3);
    cin >> D;
    cout << "Matrix E = B + C + D" << endl;
    MyMatrix E = B + C + D;
    cout << E << endl;
    MyMatrix F = A * E;
    cout << "Matrix F is A*E" << endl << F << endl;
    MyMatrix G = F * 8.0;
    cout << "Matrix G is F*8.0" << endl << G << endl;
    MyMatrix H = E - C - D;
    cout << "Matrix H = E - C - D" << endl << H << endl;
    MyMatrix H1;
    if (H == B)
        H = (double) G * H;
    else
        H = (double) H * H;
    cout << "H = (double)G*H" << endl << H << endl << endl;

    // Test 2
    cout << "Second test:" << endl;
    cout << "Enter values for 3x3 matrix I" << endl;
    MyMatrix I(3, 3);
    cin >> I;
    cout << "Creating matrices J&K using the copy constructor" << endl;
    MyMatrix J(I);
    MyMatrix K(J);
    MyMatrix L = I * J * K;
    cout << "Matrix L = I*J*K" << endl << L << endl;
    MyMatrix M(4, 4);
    cout << "Testing try & catch for L(3x3) and M(4x4): (cerr would appear at bottom of page)" << endl;
    MyMatrix N = L + M;
    cout << "N = L + M?" << endl << N << endl;
    N = L - M;
    cout << "N = L - M?" << endl << N << endl;
    N = L * M;
    cout << "N = L * M?" << endl << N << endl;
    cout << "L is:" << endl << L << endl;
    cout << "2.0 * L * 0.5 should be L:" << endl << 2.0 * L * 0.5 << endl;

    return 0;
}
