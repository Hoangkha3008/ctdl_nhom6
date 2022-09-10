//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Collections;
//namespace Demo_List
//{
//    class Array_list
//    {
//        static void khaibaokhoitaoarraylist()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//        }
//        static void chencacphantu()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            // Chèn các phần tử vào Arraylist
//            Console.WriteLine("\nChen phan tu vao ArrayList: ");
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }
//            Console.WriteLine("\n");
//        }


       
//        static void thietlapphantu()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Thiết lập số phần tử mà Arraylist có thể chứa
//            Console.WriteLine("\nDung luong cua ArrayList: {0} ",
//                arraylist.Capacity);
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }
//            Console.WriteLine("\n");
//        }
//        static void sophantuthucsuchua()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Số lượng phần tử thực sự được chứa trong Arraylist
//            Console.WriteLine("So phan tu trong ArrayList: {0}",
//                arraylist.Count);
//            Console.WriteLine("\nHien thi cac phan tu trong ArrayList: ");
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }
//            Console.WriteLine("\n");
//        }
//        static void insertphantu()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Insert phan tu 
//            Console.WriteLine("Insert phan tu :");
//            arraylist.Insert(10, 3); // in 3 ở vị trí thứ 10
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }

//            Console.WriteLine("\n");
//        }
//        static void daonguoctatca()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Đảo ngược tất cả các phần tử
//            Console.WriteLine("Dao nguoc tat ca cac phan tu :");
//            arraylist.Reverse();
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }
//            Console.WriteLine("\n");
//        }
//        static void sapxeptheothututang()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Sắp xếp theo thứ tự tăng dần 
//            Console.WriteLine("\nSap xep va hien thi ArrayList " +
//                "sau khi da sap xep: ");
//            arraylist.Sort();
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }
//            Console.WriteLine("\n");
//        }
//        static void xoaphantu()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Xóa phần tử chỉ định
//            Console.WriteLine("Xoa phan tu tai vi tri so 7 :");
//            arraylist.RemoveAt(7);
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }
//            Console.WriteLine("\n");
//        }
//        static void kiemtra()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Kiễm tra phần tử 
//            Console.WriteLine("Kiem tra phan tu :");
//            bool kiemtra = arraylist.Contains(2);

//            if (kiemtra == false)
//            {
//                Console.WriteLine("Khong tim thay phan tu trong Arraylist");
//            }
//            else
//            {
//                Console.WriteLine("Tim thay phan tu trong Arraylist");
//            }
//            Console.WriteLine();
//        }
//        static void taobansao()
//        {
//            // Tạo 1 Arraylist mới 
//            ArrayList arraylist = new ArrayList();
//            arraylist.Add(1);
//            arraylist.Add(7);
//            arraylist.Add(10);
//            arraylist.Add(4);
//            arraylist.Add(3);
//            arraylist.Add(6);
//            arraylist.Add(7);
//            arraylist.Add(2);
//            arraylist.Add(5);
//            arraylist.Add(9);
//            arraylist.Add(8);
//            // Tạo bản sao từ Array hiện tại 
//            Console.WriteLine("Ban sao moi:");
//            arraylist.Clone();
//            foreach (int i in arraylist)
//            {
//                Console.Write(i + " ");
//            }
//            Console.WriteLine("\n");
//        }
       
//        static void Main(string[] args)
//        {
//            int chon;
//            do
//            {

//                Console.WriteLine("***************MAIN MENU**********");
//                Console.WriteLine("*******Chuong trinh minh hoa cho Array List********");
//                Console.WriteLine("1.   Khai bao va khoi tao Array List");
//                Console.WriteLine("2.   Chen cac phan tu trong Array List");
//                Console.WriteLine("3.   Thiet lap phan tu");
//                Console.WriteLine("4.   So phan tu thuc su duoc chua");
//                Console.WriteLine("5.   Insert phan tu");
//                Console.WriteLine("6.   Dao nguoc tat ca cac phan tu");
//                Console.WriteLine("7.   sap xep theo thu tu tang dan");
//                Console.WriteLine("8.   xoa phan tu chi dinh");
//                Console.WriteLine("9.   kiem tra phan tu");
//                Console.WriteLine("10.   tao ban sao tu array hien tai");
//                Console.Write("    NHAP LUA  CHON CUA BAN VAO:");

//                chon = int.Parse(Console.ReadLine());
//                switch (chon)
//                {
//                    case 1:
//                        khaibaokhoitaoarraylist();
//                        break;
//                    case 2:


//                        chencacphantu();
//                        break;

//                    case 3:
//                        thietlapphantu();
//                        break;

//                    case 4:
//                        sophantuthucsuchua();
//                        break;
//                    case 5:
//                        insertphantu();
//                        break;
//                    case 6:
//                        daonguoctatca();
//                        break;
//                    case 7:
//                        sapxeptheothututang();
//                        break;
//                    case 8:
//                        xoaphantu();
//                        break;
//                    case 9:
//                        kiemtra();
//                        break;
//                    case 10:
//                        taobansao();
//                        break;
//                    default:
//                        Console.WriteLine("vui long nhap lai");
//                        break;
//                }
//            } while (chon != 11);
//            Console.ReadLine();
//        }
//    }
//}
    
           
            
            
            

           
           
            
            
            
           
           
           

       