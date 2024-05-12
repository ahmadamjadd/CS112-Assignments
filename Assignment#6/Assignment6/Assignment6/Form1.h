#pragma once
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
#include <vcclr.h> 


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		int numPolynomials;
		int numvariables;
		int numnotZeros;
		int* buff;
		String^ fileName;
		int* sum;
		double seconds;
		String^ Path;
		bool sumdone;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Button^ button2;
	public:
		
		Form1(void)
		{
			InitializeComponent();
			numPolynomials = 0;
			numvariables = 0;
			numnotZeros = 0;
			sumdone = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			delete[] buff;
			delete[] sum;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(68, 42);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(802, 204);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->WordWrap = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(991, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(68, 267);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(802, 50);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			this->richTextBox2->WordWrap = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(68, 320);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 24);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Calculate Sum";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(68, 354);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(802, 99);
			this->richTextBox3->TabIndex = 4;
			this->richTextBox3->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(68, 459);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 27);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Display Info";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(386, 538);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(179, 38);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Generate Output File";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(280, 602);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 7;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(991, 727);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Polynomial\'s Addition";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//OpeningFile
		openFileDialog1->ShowDialog();
		Path = openFileDialog1->FileName;
		fileName = Path::GetFileName(Path);
		pin_ptr<const wchar_t> wch = PtrToStringChars(Path);
		int len = Path->Length;
		wchar_t* wchPtr = const_cast<wchar_t*>(wch);
		wstring convertedString(wchPtr, len);
		string nativepath(convertedString.begin(), convertedString.end());

		ifstream ReadFile;
		ReadFile.open(nativepath);
		if (!ReadFile.is_open())
		{
			MessageBox::Show("Error opening file");
			return;
		}

		int temp1 = 0;
		int temp2 = 0;
		ReadFile >> temp1;
		numPolynomials = temp1;
		ReadFile >> temp2;
		numvariables = temp2;

		buff = new int[numvariables];
		sum = new int[numvariables];
		for (int i = 0; i < numvariables; i++)
		{
			sum[i] = 0; // Initialize sum array elements to zero
		}

		string line;
		getline(ReadFile, line); // Consume the remaining newline character after reading number_of_vars
		auto start = std::chrono::high_resolution_clock::now();
		while (getline(ReadFile, line))
		{
			istringstream iss(line);
			for (int j = 0; j < numvariables; j++)
			{
				int value;
				if (!(iss >> value))
				{
					MessageBox::Show("Error reading file");
					return;
				}
				buff[j] = value; // Store the read value in buff array
				sum[j] += buff[j]; // Update sum with the read value
				String^ intString = Convert::ToString(value); // Convert int to String
			}
		}

		for (int i = 0; i < numvariables; i++)
		{
			if (sum[i] != 0)
			{
				numnotZeros++;
			}

		}
		StreamReader^ reader = gcnew StreamReader(Path);
		String^ contents = reader->ReadToEnd();
		richTextBox1->Text = contents;
		reader->Close();

		

		ReadFile.close(); // Close the file after reading
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		seconds = duration.count() / 1000000.0;





	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (numPolynomials == 0) {

			MessageBox::Show("Please select a file first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		for (int i = 0; i < numvariables; i++)
		{
			richTextBox2->AppendText(sum[i].ToString() + "\t");
		}
		sumdone = true;
		
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (numPolynomials == 0) {

		MessageBox::Show("Please select a file first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (!sumdone) {

		MessageBox::Show("Please Calculate Sum First.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	richTextBox3->AppendText("File Name: " + fileName);
	richTextBox3->AppendText(Environment::NewLine);
	richTextBox3->AppendText("Number of Polynomials: " + numPolynomials.ToString());
	richTextBox3->AppendText(Environment::NewLine);
	richTextBox3->AppendText("Number of Variables: " + numvariables.ToString());
	richTextBox3->AppendText(Environment::NewLine);
	richTextBox3->AppendText("Number of non-zero Values: " + numnotZeros.ToString());
	richTextBox3->AppendText(Environment::NewLine);
	richTextBox3->AppendText("Data Structure Used: 1D Array");
	richTextBox3->AppendText(Environment::NewLine);
	richTextBox3->AppendText("Total Time Taken for Addition: " + seconds + "seconds");


}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (numPolynomials == 0) {
		
		MessageBox::Show("Please select a file first.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (!sumdone) {

		MessageBox::Show("Please Calculate Sum First.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	ofstream WriteFile("result_addition.txt");
	pin_ptr<const wchar_t> wch = PtrToStringChars(fileName);
	int len = fileName->Length;
	wchar_t* wchPtr = const_cast<wchar_t*>(wch);
	wstring convertedString(wchPtr, len);
	string nativepath(convertedString.begin(), convertedString.end());
	
	if (WriteFile.is_open()) {
		WriteFile << "Input File Name: " << nativepath;
		WriteFile << "\n";
		for (int i = 0; i < numvariables; i++)
		{
			WriteFile << sum[i];
			WriteFile << "\t";
		}
		WriteFile.close();
		label1->Text = "Output File has been created with name: result_addition.txt";
	}
	else {
		MessageBox::Show("Error opening output file");
	}

}
};
}
