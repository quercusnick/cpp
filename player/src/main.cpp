
#include<iostream>
#include<string>


class Decoder
{
public:
	virtual void decode(const std::string& FileName) = 0;

	virtual ~Decoder(){};
};

class VideoDecoder : public Decoder {
public:
	void decode(const std::string& FileName){
		std::string bin = "echo mplayer " + FileName;
		const char *command = bin.c_str();
		system(command);
	}
	
};

class AudioDecoder : public Decoder {
public:
	void decode(const std::string& FileName){
		std::string bin = "echo ffplay " + FileName;
		const char *command = bin.c_str();
		system(command);
	}
};

class Parser {
	public:
		Decoder* parse(const std::string& FileName){
			std::string MediaType = "UNKNOWN";
			Decoder *d;

			if (has_suffix(FileName, ".mp3"))
			{
				MediaType="AUDIO";
				d = new AudioDecoder();
			}

			if (has_suffix(FileName, ".avi"))
			{
				MediaType="VIDEO";
				d = new VideoDecoder();
			}

			return d;

		};

	private:
		bool has_suffix(const std::string &str, const std::string &suffix)
		{
    		return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
		}
};

class Player {
	public:
		void play(const std::string& FileName){
			Parser p;
			Decoder* d = p.parse(FileName);
			d->decode(FileName);
			delete d;
		};

};



int main(int argc, char** argv) {
	Player p;
	p.play(argv[1]);
	
    return 0;
}
