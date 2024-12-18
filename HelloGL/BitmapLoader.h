#pragma once
class BitmapLoader
{
private:
	typedef unsigned __int16 uint16_t;
	typedef __int32 int32_t;
	typedef unsigned __int32 uint32_t;
	typedef __int64 int64_t;
	typedef unsigned __int64 uint64_t;

	// two characters to identify the bitmap file type
	typedef struct {
		unsigned char magic[2];
	}bmpfile_ft;

	// bit map header file
	typedef struct {
		uint32_t filesz;
		uint16_t creator1;
		uint16_t creator2;
		uint32_t bmp_offset;
	}bmpfile_header;

	// bitmap info
	typedef struct {
		uint32_t header_sz;
		int32_t width;
		int32_t height;
		uint16_t nplanes;
		uint16_t bitspp;
		uint32_t compress_type;
		uint32_t bmp_bytesz;
		int32_t hres;
		int32_t vres;
		uint32_t ncolors;
		uint32_t nimpcolors;
	} BITMAPINFOHEADER;

	typedef struct {
		unsigned char b, g, r;
	} bmp_colour;

	BITMAPINFOHEADER bitMapInfo;

public:
	void LoadBitMap(char* fileName, char* outFileName);
};

