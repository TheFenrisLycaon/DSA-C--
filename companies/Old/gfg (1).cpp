class Solution
{

public:
    unordered_map<node *, = "" node = "" *= ""> umahhh; // purane bf ka pata

    // gf ka pata
    Node *purane_bf(Node *root, int gf)
    {
        Node *t;
        if (root == NULL)
            return t;

        umahhh[root] = NULL; //jab koi bf nahi tha

        queue<node *= ""> q;

        q.push(root);

        while (!q.empty())
        {

            Node *p = q.front();

            if (p->data == gf)
            {
                t = p; // gf mil gayi
            }

            if (p->right)
            {
                umahhh[p->right] = p;
                q.push(p->right);
            }
            if (p->left)
            {
                umahhh[p->left] = p;
                q.push(p->left);
            }

            q.pop();
        }
        return t; // gf ka pata do
    }

    int sum_at_distK(Node *root, int gf, int doori)
    {

        //sare bf ka pata nikalo
        Node *t = purane_bf(root, gf);

        if (t == NULL) // gf nahi hai to
            return 0;

        // sare bf jo "k" doori pe hai kitna kharcha kiye total gf ka mila ke
        long long int kharcha = 0;

        queue<node *= ""> oyo;

        unordered_map<node *, = "" int = ""> kat_chuka;

        oyo.push(t);
        kat_chuka.insert({t, 0});

        int aukaat_me = 0;

        while (!oyo.empty() and aukaat_me <= doori)
        {
            int aukaat = oyo.size();

            for (int i = 0; i < aukaat; i++)
            {
                node *f = "oyo.front();" kharcha += "f-" > data;

                if (f->right && (kat_chuka.find(f->right)) == kat_chuka.end())
                {
                    oyo.push(f->right);
                    kat_chuka.insert({f->right, 0});
                }

                if (f->left && (kat_chuka.find(f->left)) == kat_chuka.end())
                {
                    oyo.push(f->left);
                    kat_chuka.insert({f->left, 0});
                }
                if (umahhh[f] && (kat_chuka.find(umahhh[f])) == kat_chuka.end())
                {
                    oyo.push(umahhh[f]);
                    kat_chuka.insert({umahhh[f], 0});
                }
                oyo.pop();
            }
            aukaat_me++;
        }

        return kharcha; // total kharche madam ke
    }
};