#ifndef HEADERS_INCLUS_MAIN
	#define HEADERS_INCLUS_MAIN

	class IMG : public wxApp
	{
		public :
			virtual bool OnInit();
			virtual int OnExit();
	};
    
	wxDECLARE_APP(IMG);
    
#endif
