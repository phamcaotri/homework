struct bitmap {
//     int n;
//     int* a;
//     bitmap(int n, int init) {
//         this->n = n;
//         a = new int[n/32 + 1];
//     }
//     void set(int i) {
//         a[i/32] |= (1 << (i%32));
//     }
//     int operator[](int i) {
//         return (a[i/32] >> (i%32)) & 1;
//     }
// };


// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     bitmap m(50000000, 0);
//     int a, b;
//     while (cin >> a >> b) {
//         if (a == 1) {
//             m.set(b);
//         } else {
//             cout << m[b] << '\n';
//         }
//     }
//     return 0;
// }