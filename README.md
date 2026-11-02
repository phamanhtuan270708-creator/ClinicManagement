 ## QUẢN LÝ PHÒNG KHÁM TƯ NHÂN

## 1. Giới thiệu

Dự án **Quản lý phòng khám tư nhân** thiết kế dữ liệu cho các nghiệp vụ tiếp nhận bệnh nhân, lịch hẹn, lượt khám, đơn thuốc và thanh toán. Mô hình tách thông tin cá nhân của bệnh nhân khỏi dữ liệu phát sinh theo từng lượt khám, đồng thời hỗ trợ cả luồng bệnh nhân đặt lịch online và tiếp nhận trực tiếp.

Các phần nghiệp vụ thể hiện trong thiết kế dữ liệu:

- Quản lý thông tin bệnh nhân và lịch hẹn online
- Theo dõi hàng đợi chờ khám
- Lập đơn thuốc gồm các chi tiết thuốc và cách dùng
- Ghi nhận thanh toán theo chi phí thực tế của lượt khám
- Liên kết lượt khám trước để lưu thông tin tái khám

Quy chuẩn đặt tên mã nguồn: **camelCase**.

## 2. Thành viên và phân công

| STT | Họ tên | Nhiệm vụ |
|:---:|--------|----------|
| 1 | PHẠM ANH TUẤN | - Thiết kế `Patient` (bệnh nhân)<br>- Thiết kế `Appointment` (lịch hẹn online)<br>- Thiết kế `Queue` (số thứ tự chờ)<br>- Thiết kế `Visit` (lượt khám) |
| 2 | LÊ NGUYỄN MINH ĐỨC |- Thiết kế `PrescriptionItem` (chi tiết thuốc)<br>- Thiết kế `Prescription` (đơn thuốc)<br>- Thiết kế `Payment` (thanh toán)<br>- Viết README.md |

## 3. Thiết kế cấu trúc dữ liệu

| Cấu trúc (Struct) | Thuộc tính  | Mô tả & ghi chú |
|-------------------|------------------|-----------------|
| `Patient` | `patient_id`, `full_name`, `phone`, `date_of_birth` | Thông tin bệnh nhân, dùng chung cho cả luồng online và offline. |
| `Queue` | `arrival_sime`, `type`, `current_status` | Số thứ tự khám và thứ tự ưu tiên; phục vụ tiếp nhận trực tiếp hoặc khách online đã đến phòng khám. |
| `Visit` | `visit_id`, `patient_id`, `case_id`, `visit_date` | Lượt khám thực tế. `case_id` sinh mã đợt khám phân biệt tái khám và bệnh lý mới qua mỗi lượt khám. |
| `PrescriptionItem` | `medicine_id`, `quantity`, `unitprice`, `usage` | Chi tiết thuốc gồm mã thuốc, số lượng, đơn giá và cách dùng. |
| `Prescription` | `prescription_id`, `visit_id`, `items` | Đơn thuốc hoàn chỉnh. |
| `Payment` | `payment_id`, `visit_id`, `total_amount`, `payment_methods` | Thanh toán; chỉ tính phí dịch vụ thực tế phát sinh từ lượt khám. |
| `Appointment` | `appointment_id`, `patient_id`, `appointment_date`, `time_slot`, `status` | Lịch hẹn đặt trước online của bệnh nhân. |

## Hình ảnh demo chương trình
<img width="812" height="800" alt="1793622284146_8157650638589662592_8157650638589662592_e6b1f0ec3e3b1031e196767420c4ec9c" src="https://github.com/user-attachments/assets/7c8a0ef2-ea79-44a9-8855-7d8045ee4cb8" />
   <img width="812" height="660" alt="1793622307149_8157650638589662592_8157650638589662592_65f51b9e2e414114e403e9a41277b711" src="https://github.com/user-attachments/assets/23c39257-58bf-46d9-abf6-497b29565198" />
   <img width="812" height="600" alt="1793622329718_8157650638589662592_8157650638589662592_a43a2df51819eaaed840636ab2022d5c" src="https://github.com/user-attachments/assets/45872533-1987-41a7-abd9-fa3dd24da882" />
   <img width="812" height="730" alt="1793622347377_8157650638589662592_8157650638589662592_8cb13d035e02137edaa37906fc57d703" src="https://github.com/user-attachments/assets/6417a50c-6d80-4df6-aee4-9f5f81f22add" />
   <img width="812" height="796" alt="1793622364043_8157650638589662592_8157650638589662592_b181126eef7e102f901cdd7e5c364414" src="https://github.com/user-attachments/assets/b53fc5eb-a7f6-4150-8b48-917403238fb1" />
   <img width="812" height="817" alt="1793622387440_8157650638589662592_8157650638589662592_91ac6ef2481e99d69b711f3ef1fc2e05" src="https://github.com/user-attachments/assets/f4e31d99-591e-49a9-bab1-252084ea9993" />
   <img width="812" height="812" alt="1793622402305_8157650638589662592_8157650638589662592_fcb23fa4d7f5a01e8eb377d3ece96b73" src="https://github.com/user-attachments/assets/7080ed8e-88d1-45f8-b19d-a3299ed04606" />
   <img width="812" height="776" alt="1793622414637_8157650638589662592_8157650638589662592_659513a6dbe0ae5529816da11a0b8a95" src="https://github.com/user-attachments/assets/7c51537e-499f-4f94-b3c9-62ae51de171f" />
   <img width="812" height="787" alt="1793622426750_8157650638589662592_8157650638589662592_d14de8420811da0d2ddaf9667ce22f53" src="https://github.com/user-attachments/assets/59dfffd8-b828-4a23-a2e5-70a16af98312" />
   <img width="812" height="436" alt="1793622441497_8157650638589662592_8157650638589662592_283072fcb60e3797b9e93a69b03de0da" src="https://github.com/user-attachments/assets/631fe5f0-eebe-4f14-aae3-32b22574e592" />
   <img width="812" height="802" alt="1793622459865_8157650638589662592_8157650638589662592_1a51d41947b9e1d290303055db4244bb" src="https://github.com/user-attachments/assets/dda81cef-c5b5-4a2a-99a4-1ce716f6a980" />
   <img width="812" height="537" alt="1793622471852_8157650638589662592_8157650638589662592_545cdd729508a678ecce2764303799c6" src="https://github.com/user-attachments/assets/5e38cd49-10a2-466d-ac14-70ed74d23655" />



# HƯỚNG DẪN CÀI VÀ BIÊN DỊCH
Hướng dẫn chi tiết cách thiết lập môi trường, biên dịch mã nguồn và chạy chương trình Clinic Management trên máy tính cá nhân.

## ***1. Yêu cầu hệ thống***

* Để biên dịch và chạy được dự án C/C++ này, máy tính của bạn cần trang bị các công cụ sau:

* Trình biên dịch C/C++ (Compiler): GCC / G++ (Khuyên dùng bộ công cụ MinGW-w64 hoặc w64devkit trên Windows, GCC trên Linux/macOS).

* Trình chỉnh sửa mã nguồn (IDE/Code Editor): Visual Studio Code (hoặc Dev-C++, Code::Blocks).

## ***2. Tải mã nguồn về máy***

* Mở Terminal (hoặc Git Bash / Command Prompt) trên máy tính và chạy lệnh sau để tải dự án từ GitHub:

   ```git clone https://github.com/phamanhtuan270708-creator/ClinicManagement.git```

   ```cd ClinicManagement```


## ***3. Hướng dẫn biên dịch dự án***

* Dự án gồm nhiều file nguồn (.c) và file định nghĩa chung (.h). Cần biên dịch gộp toàn bộ các file nguồn cùng một lúc.

### ***Cấu trúc file mã nguồn:***

* clinic.h: File header chứa các cấu trúc dữ liệu (struct), macro định nghĩa và hàm tiện ích dùng chung.

* main.c File chính chứa luồng điều hướng Menu (int main()).

* patientandqueue.c: Module quản lý danh sách bệnh nhân và hàng chờ.

* prescription.c: Module quản lý đơn thuốc và thanh toán.
  
* utils.c: Module xóa bộ nhớ đệm tránh tình trạng trôi chương trình.

* appointment.c: Module quản lý lịch hẹn online.

### ***Lệnh biên dịch chuẩn:***

##### Mở Terminal tại thư mục gốc của dự án và chạy lệnh:

```g++ main.c patientandqueue.c prescription.c records.c visit.c utils.c appointment.c -o ClinicManagement.exe```

> Lưu ý: Không biên dịch riêng lẻ từng file .c (ví dụ: g++ main.c)

## ***4. Hướng dẫn chạy chương trình***

##### Sau khi biên dịch thành công, trình biên dịch sẽ tạo ra file thực thi ClinicManagement.exe.

#### *Windows:*

* PowerShell (VS Code):

> .\ClinicManagement.exe

* Command Prompt (CMD):

> ClinicManagement.exe


#### *Linux / macOS:*

> ./ClinicManagement.exe


