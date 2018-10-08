#include "pch.h"
#include "../PicoYPlaca/Hour.h"
#include "../PicoYPlaca/Date.h"
#include "../PicoYPlaca/PlateNumber.h"
#include "../PicoYPlaca/PicoYPlacaVerficator.h"

/*TEST FOR PlateNumber class*/
TEST(TestPlateNumberCase, TestReceivePlateNumber) {

	string RealResult;
	string ExpectedResult = "pcs-1878";
	PlateNumber PlateTest;
	RealResult = PlateTest.ReceivePlateNumber("pcs-1878");
	EXPECT_EQ(RealResult, ExpectedResult);
	EXPECT_TRUE(true);
}

TEST(TestPlateNumberCase, TestCheckPlateNumberTrue) {

	bool RealResult;
	PlateNumber PlateTest;
	RealResult = PlateTest.CheckPlateNumber("pbs-9051");
	ASSERT_TRUE(RealResult);
}

TEST(TestPlateNumberCase, TestCheckPlateNumberFalse) {

	bool RealResult;
	PlateNumber PlateTest;
	RealResult = PlateTest.CheckPlateNumber("pc7-1878");
	ASSERT_FALSE(RealResult);
}

/*TEST FOR Date class*/

TEST(TestDateCase, TestReceiveDate) {

	string RealResult;
	string ExpectedResult = "Jueves 8 de noviembre de 2018";
	Date DateTest;
	RealResult = DateTest.ReceiveDate("08/11/2018");
	EXPECT_EQ(RealResult, ExpectedResult);
	EXPECT_TRUE(true);
}

TEST(TestDateCase, TestCheckDateTrue) {
	bool RealResult;
	Date DateTest;
	RealResult = DateTest.CheckDate("15/10/2019");
	ASSERT_TRUE(RealResult);
}

TEST(TestDateCase, TestCheckDateFalse) {

	bool RealResult;
	Date DateTest;
	RealResult = DateTest.CheckDate("30:12/2018");
	ASSERT_FALSE(RealResult);
}

TEST(TestDateCase, TestVerifyDayMonthTrue) {
	
	bool RealResult;
	Date DateTest;
	RealResult = DateTest.VerifyDayMonth(31,03);
	ASSERT_TRUE(RealResult);
}

TEST(TestDateCase, TestVerifyDayMonthFalse) {

	bool RealResult;
	Date DateTest;
	RealResult = DateTest.VerifyDayMonth(31,02);
	ASSERT_FALSE(RealResult);
}

TEST(TestDateCase, TestPrintDate) {

	string RealResult;
	string ExpectedResult = "Domingo 15 de septiembre de 2019";
	Date DateTest;
	RealResult = DateTest.PrintDate(15,9,2019);
	EXPECT_EQ(RealResult, ExpectedResult);
	EXPECT_TRUE(true);
}

/*TEST FOR Hour class*/
TEST(TestHourCase, TestReceiveHour) {

	string RealResult;
	string ExpectedResult = "21:20";
	Hour HourTest;
	RealResult = HourTest.ReceiveHour("21:20");
	EXPECT_EQ(RealResult, ExpectedResult);
	EXPECT_TRUE(true);
}

TEST(TestHourCase, TestChecHourTrue) {

	bool RealResult;
	Hour HourTest;
	RealResult = HourTest.CheckHour("07:19");
	ASSERT_TRUE(RealResult);
}
TEST(TestHourCase, TestCheckHourFalse) {

	bool RealResult;
	Hour HourTest;
	RealResult = HourTest.CheckHour("25:85");
	ASSERT_FALSE(RealResult);
}

/*TEST FOR PicoYPlacaVerficator class*/

TEST(TestPicoYPlacaVerficatorCase, TestPicoYPlacaVerficatorTrue) {

	string RealResult;
	string ExpectedResult = "No puede transitar, tiene pico y placa.";
	PicoYPlacaVerficator PicoYPlacaVerificatorTest;
	RealResult = PicoYPlacaVerificatorTest.PicoYPlacaValidator("pcs-8488","Jueves 4 de octubre de 2018","18:32");
	EXPECT_EQ(RealResult, ExpectedResult);
	EXPECT_TRUE(true);
}

TEST(TestPicoYPlacaVerficatorCase, TestPicoYPlacaVerficatorFalse) {

	string RealResult;
	string ExpectedResult = "Puede transitar libremente.";
	PicoYPlacaVerficator PicoYPlacaVerificatorTest;
	RealResult = PicoYPlacaVerificatorTest.PicoYPlacaValidator("gye-2536", "Miercoles 14 de noviembre de 2018", "12:10");
	EXPECT_EQ(RealResult, ExpectedResult);
	EXPECT_TRUE(true);
}