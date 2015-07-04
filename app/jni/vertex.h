class Vertex {
	private:
		int id;
		int distance;

	public:
		Vertex() {
			this->id=0;
			this->distance = 0;
		}
		Vertex(int id, int distance) {
			this->id = id;
			this->distance = distance;
		}
	public:
		int getId() {
			return this->id;
		}

		int getDistance() {
			return this->distance;
		}

		void setId(int& id) {
			this->id = id;
		}

		void setDistance(int& distance) {
			this->distance = distance;
		}
		
		bool operator<(const Vertex& a) const {
			return (&a)->distance < this->distance;
		}
};
