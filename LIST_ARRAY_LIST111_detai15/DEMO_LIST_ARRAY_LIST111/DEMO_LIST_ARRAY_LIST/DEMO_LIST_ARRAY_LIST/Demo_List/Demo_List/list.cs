using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ListTrongCSharp
{
    class list
    {

        static void khaibaokhoitaolist()
        {
            // Khai báo và khởi tạo List

            List<int> List = new List<int>(); // khởi tạo 1 List các số nguyên rỗng

            Console.WriteLine("Danh sach so nguyen :\n ");
            List<int> List2 = new List<int>() { 7, 8, 9, 10, 5, 3, 4, 1 }; // khởi tạo 1 List các số nguyên
            foreach (var item in List2)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine("\n");



        }
        static void travecacphantutrongdanhsach()
        {
            Console.WriteLine("In các phan tu lon hon 5:\n");
            List<int> List2 = new List<int>() { 7, 8, 9, 10, 5, 3, 4, 1 };
            //FindAll trả về tất cả các phần tử trong danh sách
            var t = List2.FindAll(
                (e) => { return e > 5; }
                );
            foreach (var n in t)
            {
                Console.Write(n);
            }
            Console.WriteLine();
        }
        static void duyetcacphantucuamang()
        {
            //Duyệt các phần tử của mảng
            List<int> List2 = new List<int>() { 7, 8, 9, 10, 5, 3, 4, 1 };
            Console.WriteLine("\n");
            Console.WriteLine("Duyet cac phan tu cua mang:");
            for (var i = 0; i < List2.Count; i++)
            {
                Console.WriteLine($"{ List2[i]}\t");
            }

            Console.WriteLine();
        }
        static void sapxeptheothututangdan()
        {
            List<int> List2 = new List<int>() { 7, 8, 9, 10, 5, 3, 4, 1 };
            // Sắp xếp theo thứ tự tăng dần
            Console.WriteLine("Sap xep tang  :\n ");
            List2.Sort();
            foreach (var item in List2)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine();
        }
        static void inphantutronglist()
        {
            //  Tạo 1 List các kiểu string và thêm 2 phần tử vào List.


            List<string> List4 = new List<string>();
            List4.Add("NguyenHoangKha \n");
            List4.Add("LeHoangNhut \n");
            List4.Add("NguyenTrongLiem \n");
            List4.Add("NguyenQuocHoang Son \n");
            List4.Add("NguyenMinhTriet \n");

            // In giá trị các phần tử trong List
            Console.WriteLine(" List ban dau: ");
            Console.WriteLine(" So luong phan tu trong List la: {0}", List4.Count);
            foreach (string item in List4)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine();
        }
        static void ingiatriduocchen()
        {
            List<string> List4 = new List<string>();
            List4.Add("NguyenHoangKha \n");
            List4.Add("LeHoangNhut \n");
            List4.Add("NguyenTrongLiem \n");
            List4.Add("NguyenQuocHoang Son \n");
            List4.Add("NguyenMinhTriet \n");
            // Chèn 1 phần tử vào đầu List.
            List4.Insert(0, "NguyenVanA \n");
            // In lại giá trị các phần tử trong List để xem đã chèn được hay chưa
            Console.WriteLine(" List sau khi insert: ");
            Console.WriteLine(" So luong phan tu trong List la: {0}", List4.Count);
            foreach (string item in List4)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine();
        }
        static void kiemtra1phantutronglistcotontaihayko()
        {
            List<string> List4 = new List<string>();
            List4.Add("NguyenHoangKha \n");
            List4.Add("LeHoangNhut \n");
            List4.Add("NguyenTrongLiem \n");
            List4.Add("NguyenQuocHoang Son \n");
            List4.Add("NguyenMinhTriet \n");
            // Kiểm tra 1 phần tử có tồn tại trong List hay không.
            bool isExists = List4.Contains("NguyenTrongLiem \n");

            if (!isExists)
            {
                Console.WriteLine("Khong tim thay chuoi trong List");
            }
            else
            {
                Console.WriteLine("Tim thay chuoi trong List");
            }
        }
        static void xoaphantu()
        {
            List<string> List4 = new List<string>();
            List4.Add("NguyenHoangKha \n");
            List4.Add("LeHoangNhut \n");
            List4.Add("NguyenTrongLiem \n");
            List4.Add("NguyenQuocHoang Son \n");
            List4.Add("NguyenMinhTriet \n");
            // xoa phan tu 
            Console.WriteLine("Xoa phan tu :\n");
            List4.Remove("NguyenTrongLiem \n");
            foreach (string item in List4)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine("\n");
        }
        static void daonguocphantu()
        {
            List<string> List4 = new List<string>();
            List4.Add("NguyenHoangKha \n");
            List4.Add("LeHoangNhut \n");
            List4.Add("NguyenTrongLiem \n");
            List4.Add("NguyenQuocHoang Son \n");
            List4.Add("NguyenMinhTriet \n");
            //Đảo ngược các phần tử trong List
            Console.WriteLine("Dao nguoc tat ca cac phan tu :\n");
            List4.Reverse();
            foreach (string item in List4)
            {
                Console.Write(" " + item);
            }

            Console.ReadLine();
        }


        static void Main(string[] args)
        {
            int chon;
            do
            {

                Console.WriteLine("***************MAIN MENU**********");
                Console.WriteLine("*******Chuong trinh minh hoa cho List********");
                Console.WriteLine("1.   KHAI BAO VA KHOI TAO LIST");
                Console.WriteLine("2.   TRA VE TAT CA CAC PHAN TU TRONG DANH SACH");
                Console.WriteLine("3.   DUYET CAC PHAN TU CUA MANG");
                Console.WriteLine("4.   SAP XEP THEO THU TU TANG DAN");
                Console.WriteLine("5.   IN GIA TRI CAC PHAN TU TRONG LIST");
                Console.WriteLine("6.   IN GIA TRI CAC PHAN TU TRONG LIST DE XEM CHEN DC HAY CHUA");
                Console.WriteLine("7.   KIEM TRA 1 PHAN TU CO TON TAI TRONG LIST KO");
                Console.WriteLine("8.   XOA PHAN TU");
                Console.WriteLine("9.   DAO NGUOC PHAN TU TRONG LIST");
                Console.Write("    NHAP LUA  CHON CUA BAN VAO:");

                chon = int.Parse(Console.ReadLine());
                switch (chon)
                {
                    case 1:
                        khaibaokhoitaolist(); break;
                    case 2:


                        travecacphantutrongdanhsach();
                        break;

                    case 3:
                        duyetcacphantucuamang();
                        break;

                    case 4:
                        sapxeptheothututangdan();
                        break;
                    case 5:
                        inphantutronglist();
                        break;
                    case 6:
                        ingiatriduocchen();
                        break;
                    case 7:
                        kiemtra1phantutronglistcotontaihayko();
                        break;
                    case 8:
                        xoaphantu();
                        break;
                    case 9:
                        daonguocphantu();
                        break;
                    default:
                        Console.WriteLine("vui long nhap lai");
                        break;
                }
            } while (chon != 9);
            Console.ReadLine();
        }
    }
}
