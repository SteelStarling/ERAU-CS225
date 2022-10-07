#include <iostream>
using namespace std;

// int functionWithDefaults(int a, int b = 0, int c = 0) {
//     return 0;
// }

// int main() {
//     functionWithDefaults(1);
//     functionWithDefaults(123, 2);
//     functionWithDefaults(123, 2, 5);
// }

// class Invoice {
//     private:
//         int num;
//         static int outstanding;
//     public:
//         Invoice() {
//             num = outstanding;
//             cout << "NEW INVOICE #" << num << endl;
//             outstanding++;
//         }
//         ~Invoice() {
//             cout << "INVOICE #" << num << " PAID" << endl;
//             outstanding--;
//         }
// };

// int Invoice::outstanding = 0;

// int main() {
//     Invoice i;
//     Invoice i2;
//     Invoice i3;
// }

// class Rectangle {
//     protected:
//         int length;
//         int width;
//     public:
//         Rectangle() {
//             length = 5;
//             width = 3;
//         }

//         Rectangle(int l, int w) {
//             length = l;
//             width = w;
//         }

//         virtual void display() /*{*/ = 0;
//         //     cout << "The Rectangle has a length of " << length << " and width of " << width << endl;
//         // }
// };

// class ColorfulRectangle : public Rectangle {
//     protected:
//         string color;
//     public:
//         ColorfulRectangle(int l, int w, string color) {
//             length = l;
//             width = w;
//             this->color = color;
//         }

//         void display() {
//             cout << "The Rectangle has a length of " << length << ", width of " << width << " and color of " << color << endl;
//         }
// };

// int main() {
//     ColorfulRectangle c(5,4,"Green");
//     c.display();
// }