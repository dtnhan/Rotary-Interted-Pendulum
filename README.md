# Rotary-Interted-Pendulum

Luận văn này trình bày về đề tài điều khiển con lắc ngược một bậc tự do. Luận văn sẽ
trình bày về cơ sở các lý thuyết được áp dụng, chi tiết các phần như thiết kế cơ khí của mô
hình, tìm hiểu và xây dựng mô hình toán, xây dựng và tiến hành mô phỏng mô hình trên
Matlab, xây dựng các khối điều khiển trên thư viện nhúng và thiết kế giao diện điều khiển.
Việc thiết kế cơ khí của mô hình chủ yếu dựa vào các mẫu mô hình hiện có từ các
nghiên cứu về con lắc ngược trong và ngoài nước để thiết kế lên mô hình đơn giản và phù hợp
nhất với nhu cầu của luận văn, sau đó xây dựng lên mô hình toán để tiến hành mô phỏng trên
chương trình Simulink của Matlab để khảo sát các đặc tuyến và thông số của mô hình, và dựa
vào các thông số đó mà tiến hành thiết kế khâu điều khiển mô hình mô phỏng theo nhu cầu
của đề tài.

Tiếp đến, để chạy mô hình thực tế dựa trên bộ điều khiển mô phỏng, ta kết nối qua thư
viện nhúng hỗ trợ trên Matlab Simulink. Người thực hiện sử dụng thư viện Waijung, một thư
viện hỗ trợ nhúng từ Matlab cho kit ứng dụng STM32F4 DISCOVERY của hãng
STMicroelectronics, để xây dựng các khối nhúng xử lý các tín hiệu đầu vào và xuất tín hiệu
đầu ra, đồng thời sử dụng các khối chức năng hỗ trợ sẵn có trên thư viện nhúng để xây dựng
giải thuật điều khiển theo mô hình thực tế. Sau khi đã xây dựng xong mô hình các khối chức
năng, người thực hiện sẽ tiến hành biên dịch các khối đó thành các đoạn mã Code C và nạp
xuống vi điều khiển để chạy ứng dụng. Đồng thời, những người thực hiện sẽ xây dựng giao
diện người dùng trên máy tính để giám sát và đánh giá chất lượng điều khiển thực tế. Các tín
hiệu hồi tiếp thực tế sẽ được vi điều khiển thu thập và gửi lên máy tính qua khối truyền thông
nối tiếp sử dụng IC FT232 USB – Serial. Việc so sánh các tín hiệu đó với các đặc tuyến mô
phỏng sẽ giúp cho những người thực hiện chỉnh định các thông số của bộ điều khiển để hệ
thống đạt được chất lượng tốt nhất.

Và cuối cùng, khi việc điều khiển mô hình thực tế đã thực hiện tốt, những người thực
hiện sẽ đánh giá chất lượng điều khiển và rút ra kết luận của luận văn, đồng thời đề ra hướng
phát triển của luận văn.
