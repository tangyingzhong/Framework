#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tool_UnitTest
{
	TEST_CLASS(FileTest)
	{
	public:
		TEST_METHOD(Test_Open)
		{
			File FileHelper;

			Assert::IsTrue(FileHelper.Open(_T("D:\\SysConf.json"), File::FileMode::OPEN));

			FileHelper.Close();

			Assert::IsTrue(FileHelper.Open(_T("D:\\SysConf1.json"), File::FileMode::CREATE));

			FileHelper.Close();

			Assert::IsFalse(FileHelper.Open(_T("D:\\SysConf.json"), File::FileMode::CREATENEW));

			FileHelper.Close();

			Assert::IsTrue(FileHelper.Open(_T("D:\\SysConf.json"), File::FileMode::OPENORCREATE));

			FileHelper.Close();

			Assert::IsTrue(FileHelper.Open(_T("D:\\SysConf.json"), File::FileMode::TRUNC));

			FileHelper.Close();
		}

		TEST_METHOD(Test_Read)
		{
			File FileHelper;

			Assert::IsTrue(FileHelper.Open(_T("D:\\SysConf.json"), File::FileMode::OPEN));

			Array<SByte> DataArray(1024);

			Assert::IsTrue(FileHelper.Read(DataArray.Data(), 0, DataArray.Size()) != 0);

			std::string strData = DataArray.Data();

			FileHelper.Close();
		}

		TEST_METHOD(Test_Write)
		{
			File FileHelper;

			Assert::IsTrue(FileHelper.Open(_T("D:\\SysConf.json"), File::FileMode::OPEN));

			Array<SByte> DataArray(3*1024*1024);

			Assert::IsTrue(FileHelper.Read(DataArray.Data(), 0, DataArray.Size()) != 0);

			std::string strData = DataArray.Data();

			FileHelper.Close();

			Assert::IsTrue(FileHelper.Open(_T("D:\\SysConf16.json"), File::FileMode::CREATE));

			Assert::IsTrue(FileHelper.Write(strData.c_str(), 0, strData.length()) != 0);

			FileHelper.Close();
		}

		TEST_METHOD(Test_Create)
		{
			File FileHelper;

			Assert::IsTrue(FileHelper.Create(_T("D:\\SysConf26.json")));
		}

		TEST_METHOD(Test_GetSize)
		{
			File FileHelper;

			Assert::IsTrue(FileHelper.Open(_T("D:\\OSSystem.zip"), File::FileMode::OPEN));

			File::FileSize iSize = FileHelper.GetSize();

			UInt64 iMax = 4294967296;

			Assert::IsTrue(iSize >iMax);
		}

		TEST_METHOD(Test_IsExisted)
		{
			Assert::IsTrue(File::IsExisted(_T("D:\\SysConf.json")));

			Assert::IsFalse(File::IsExisted(_T("D:\\SysConf1.json")));
		}

		TEST_METHOD(Test_Delete)
		{
			Assert::IsTrue(File::Delete(_T("D:\\SysConf1.json")));

			Assert::IsFalse(File::Delete(_T("D:\\SysConf2.json")));
		}

		TEST_METHOD(Test_Move)
		{
			String strSrcPath = _T("E:\\360\\SysConf.json");

			String strDestPath = _T("D:\\TG\\SysConfigurator.json");

			Assert::IsTrue(File::Move(strSrcPath, strDestPath));
		}

		TEST_METHOD(Test_Rename)
		{
			String strSrcPath = _T("E:\\SysConfigurator.json");

			String strDestPath = _T("D:\\ATG\\SysConfigurator.json");

			Assert::IsTrue(File::Rename(strSrcPath, strDestPath));
		}

		TEST_METHOD(Test_Copy)
		{
			String strSrcPath = _T("D:\\SysConfigurator.json");

			String strDestPath = _T("E:\\ATG1\\SysConfigurator.json");

			Assert::IsTrue(File::Copy(strSrcPath, strDestPath));
		}
	};
}