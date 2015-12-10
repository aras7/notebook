const int MAX = 200000 + 7;

typedef int NUM;
NUM tree[2 * MAX];
class SegmentTree {
	private:	
		NUM idempotent;
		int n;

		NUM __update(int current_node, int low, int high, int value, int low_represented, int high_represeted)
		{	
			if(high < low_represented || low > high_represeted)
				return tree[current_node];

			if(low_represented == high_represeted)
				tree[current_node] = F(value, idempotent);
			else 
			{
				int mid = (low_represented + high_represeted) / 2;

				NUM a = __update(2 * current_node, low, high, value, low_represented, mid);
				NUM b = __update(2 * current_node + 1, low, high, value, mid + 1, high_represeted);

				tree[current_node] = F(tree[2 * current_node], tree[2 * current_node + 1]);
			}

			return tree[current_node];
		}

		NUM __query(int node, int low, int high, int low_represented, int high_represeted) {
			if(high < low_represented || low > high_represeted)
				return idempotent;

			if(low <= low_represented && high_represeted <= high)
				return tree[node];

			int mid = (low_represented + high_represeted) / 2;

			NUM a = __query(2 * node, low, high, low_represented, mid);
			NUM b = __query(2 * node + 1, low, high, mid + 1, high_represeted);

			return F(a, b);
		}

	public:
		SegmentTree() {}
		SegmentTree(int _n, NUM idemp, bool fill){
			Init(_n, idemp, fill);
		}

		void Init(int _n, NUM idemp, bool fill){
			n = _n;
			idempotent = idemp;

			if(fill)
				for(int i = 0; i < 2*n+7;i++)
					tree[i] = 0;
		}

		// sum -> change it for 'logic business'
		NUM F(NUM a, NUM b) {
			return a + b;
		}

		// build(arr, 1, 0, n-1)
		void build(NUM data[], int current_node, int low, int high) {
			if(low == high)
				tree[current_node] = F(data[low], idempotent);
			else
			{
				int mid = (low + high) / 2;

				build(data, 2 * current_node, low, mid);
				build(data, 2 * current_node + 1, mid + 1, high);

				tree[current_node] = F(tree[2 * current_node], tree[2 * current_node + 1]);
			}
		}

		NUM update(int low, int high, int value) {
			return __update(1, low, high, value, 0, n-1);
		}

		NUM query(int low, int high) {
			return __query(1, low, high, 0, n-1);
		}

		void P(int n) {
			for(int i = 0; i < n;i++)
				printf("%d ", tree[i]);
			puts("");
		}
};

segment_tree.Init(n, 0, true);
segment_tree.build(data, 1, 0, n-1)
segment_tree.update(i, j, value);
segment_tree.query(i, j);

