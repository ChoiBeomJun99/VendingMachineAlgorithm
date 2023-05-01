#include<iostream>
#include<string>

using namespace std;

class Money { //���� ���� Ŭ�����̴�.
protected:

	// �� ������ �ش��ϴ� ���� ������ �ǹ��Ѵ�.
	int coin_500;
	int coin_100;
	int coin_50;
	int coin_10;

public:

	Money() {

	}

	Money(int coin_500, int coin_100, int coin_50, int coin_10) {
		this->coin_500 = coin_500;
		this->coin_100 = coin_100;
		this->coin_50 = coin_50;
		this->coin_10 = coin_10;
	}



};

class Hopper : public Money {
	
private : 
	// total�� ��ü�� ���� �� ���� �Ѿ��� ��Ÿ����.
	int total;

public:

	Hopper(int coin_500, int coin_100, int coin_50, int coin_10) {
		this->coin_500 = coin_500;
		this->coin_100 = coin_100;
		this->coin_50 = coin_50;
		this->coin_10 = coin_10;

		total = (500 * this->coin_500) + (100 * this->coin_100) + (50 * this->coin_50) + (10 * this->coin_10);
	}

	int getTotal() {
		return total;
	}

	int getCount500() {
		return coin_500;
	}

	int getCount100() {
		return coin_100;
	}

	int getCount50() {
		return coin_50;
	}

	int getCount10() {
		return coin_10;
	}

	void plusCoin500(int hap) {
		this->coin_500 += hap;
	}

	void plusCoin100(int hap) {
		this->coin_100 += hap;
	}

	void plusCoin50(int hap) {
		this->coin_50 += hap;
	}

	void plusCoin10(int hap) {
		this->coin_10 += hap;
	}

	void minusCoin500(int minus) {
		this->coin_500 -= minus;
	}

	void minusCoin100(int minus) {
		this->coin_100 -= minus;
	}

	void minusCoin50(int minus) {
		this->coin_50 -= minus;
	}

	void minusCoin10(int minus) {
		this->coin_10 -= minus;
	}
};

class Menu { //�޴��� ���� Ŭ�����̴�.
private:

	int cost;
	int count;

public:

	Menu() {

	}

	Menu(int cost, int count) {
		this->cost = cost;
		this->count = count;
	}

	void plusCount() {
		this->count++;
	}

	void minusCount() {
		this->count--;
	}

	int getCost() {
		return this->cost;
	}

	int getCount() {
		return this->count;
	}

};

class VendingMachine { //���Ǳ⿡ ���� Ŭ�����̴�.
private:

	//���ǱⰡ ������ �ִ� �Ž������� ���� �� ���� ���� ������� ������ �ʱ�ȭ ���ش�.
	Hopper *coinChanger;
	int bill_1000 = 0; //1000�� ¥�� ������ ����

	Menu *Cola;
	Menu *Cider;
	Menu *Juice;

	
	int sell_menu[3] = { 0, 0, 0 }; //�� �޴��� �Ǹ��� ����
	int sell_total=0 ; //�Ǹűݾ�
	int input_total; // ����ڰ� ���� �ݾ�
public:

	VendingMachine(){
		coinChanger = new Hopper(0, 10, 10, 10);
		
		Cola = new Menu(1000, 5);
		Cider = new Menu(1200, 5);
		Juice = new Menu(1500, 5);
	}

	void change(int inputTotal) {
		
		int arrayCoinCount[4] = { 0, 0, 0, 0 };
		int array[4] = {500, 100, 50, 10 };

		for (int i = 0; i < 4; i++) {

			while (inputTotal >= array[i]) {
				
				if (array[i] == 500) {
					if (coinChanger->getCount500() > 0) {
						inputTotal -= array[i];
						coinChanger->minusCoin500(1);
						arrayCoinCount[i] ++;
					}else {
						break;
					}
				}
				else if (array[i] == 100) {
					if (coinChanger->getCount100() > 0) {
						inputTotal -= array[i];
						coinChanger->minusCoin100(1);
						arrayCoinCount[i] ++;
					}else {
						break;
					}
				}
				else if (array[i] == 50) {
					if (coinChanger->getCount50() > 0) {
						inputTotal -= array[i];
						coinChanger->minusCoin50(1);
						arrayCoinCount[i] ++;
					}else {
						break;
					}
				}
				else if (array[i] == 10) {
					if (coinChanger->getCount10() > 0) {
						inputTotal -= array[i];
						coinChanger->minusCoin10(1);
						arrayCoinCount[i] ++;
					}else {
						break;
					}
				}
				
			}

		}

		int result = 0;

		result = (500 * arrayCoinCount[0]) + (100 * arrayCoinCount[1]) + (50 * arrayCoinCount[2]) + (10 * arrayCoinCount[3]);

		cout << endl;
		cout << "-----------�Ž��� �� ���------------" << endl;
		cout << "500�� ¥�� :  " << arrayCoinCount[0] << " �� " << endl;
		cout << "100�� ¥�� :  " << arrayCoinCount[1] << " �� " << endl;
		cout << "50�� ¥�� :  " << arrayCoinCount[2] << " �� " << endl;
		cout << "10�� ¥�� :  " << arrayCoinCount[3] << " �� " << endl;
		cout << "�� " << result << " ��" << endl;
		this->input_total -= result;

	}

	void plusBill1000(int hap) {
		this->bill_1000 += hap;
	}

	void buy(int input_total, int menu) {

		switch (menu) {
			case 1:
				if ((this->input_total >= this->Cola->getCost()) && (this->Cola->getCount() > 0)) {

					cout << "�ݶ� �����Ͽ����ϴ�." << endl;
					this->sell_menu[0] += 1;
					this->input_total -= Cola->getCost();
					this->sell_total += Cola->getCost();
					Cola->minusCount();
					break;
				}
				else {
					cout << "�ݾ��� �����ϰų� �ݶ��� ������ �����մϴ�. " << endl;
					break;
				}

			case 2:
				if ((this->input_total >= this->Cider->getCost()) && (this->Cider->getCount() > 0)) {

					cout << "���̴ٸ� �����Ͽ����ϴ�." << endl;
					this->sell_menu[1] += 1;
					this->sell_total += Cider->getCost();
					this->input_total -= Cider->getCost();
					Cider->minusCount();
					break;
				}
				else {
					cout << "�ݾ��� �����ϰų� ���̴��� ������ �����մϴ�. " << endl;
					break;
				}

			case 3:
				if ((this->input_total >= this->Juice->getCost()) && (this->Juice->getCount() > 0)) {
					cout << "�ֽ��� �����Ͽ����ϴ�." << endl;
					this->sell_menu[2] += 1;
					this->sell_total += Juice->getCost();
					this->input_total -= Juice->getCost();
					Juice->minusCount();
					break;
				}
				else {
					cout << "�ݾ��� �����ϰų� �ֽ��� ������ �����մϴ�. " << endl;
					break;
				}

			default:
				cout << " �߸��� ��ȣ �Դϴ�. " << endl;
				break;
		}
	}

	void start() { //���� ���

		int tmp;
		
		if (this->coinChanger->getTotal() > 1500) { // �Ž������� �� �� �ִ� ���ǿ� �������� ���Ѵٸ� ������� �Ѵ�.
			
			cout << "���Ǳ� ��� ���� (1.� 2.�������� 3.������) : ";
			cin >> tmp;

			if (tmp == 1) {
				operating();
			}
			else if (tmp == 2) {
				maintenance();
			}
			else if (tmp == 3) {
				return;
			}
			else {
				cout << "�߸��� �Է��Դϴ�." << endl;
			}
		}
		else {
			cout << endl;
			cout << "�Ž����� �������� ���� � �Ұ�" << endl;
			return;
		}

		

	}

	void operating() { //� ���

		int tmp = 0;
		int pay, count;
		int total = 0;


		while (tmp != 3) {
			cout << endl;
			cout << "���� Ȥ�� ������ ���� �Ͻʽÿ�. (���� ���� �� �� : "<< this->input_total << " �� " << "1. ���� ����, 2. ���� ����, 3. ���� �׸��ϱ� : ";
			cin >> tmp;

			if (tmp == 1) {
				cout << endl;
				cout << "���� ������ �ּ��� 1000�� ¥���� ���� (�Է� ���� : 2 -> 1000�� ¥�� 2��) : ";
				cin >> count;
				this->plusBill1000(count);

				this->input_total += 1000 * count;
			}
			else if (tmp == 2) {
				cout << endl;
				cout << "������ ������ �ּ��� (�Է� ���� : 500 2 -> 500�� ¥�� 2��) : ";
				cin >> pay >> count;

				switch (pay) {
				case 500:
					coinChanger->plusCoin500(count);
					this->input_total += pay * count;
					break;
				case 100:
					coinChanger->plusCoin100(count);
					this->input_total += pay * count;
					break;
				case 50:
					coinChanger->plusCoin50(count);
					this->input_total += pay * count;
					break;
				case 10:
					coinChanger->plusCoin10(count);
					this->input_total += pay * count;
					break;
				default:
					cout << "�߸��� ���� �� �Դϴ�." << endl;
					break;
				}
			}


		}

		while (tmp != 4) {
			cout << endl;
			cout << "� ���Ḧ �����Ͻðڽ��ϱ�? ( ���� �ݾ� : " << this->input_total << " ) \n" << "1. �ݶ�(1000��) 2. ���̴�(1200��) 3. �꽺(1500��) 4. �׸� �����ϱ� (�Ž��� �� �ޱ�) : ";
			cin >> tmp;

			if (tmp == 1) {
				this->buy(this->input_total, 1);
			}
			else if (tmp == 2) {
				this->buy(this->input_total, 2);
			}
			else if (tmp == 3) {
				this->buy(this->input_total, 3);
			}

		}

		this->change(this->input_total);
		this->start();

		
	}

	void maintenance() { //�������� ��� 

		int tmp = 0;
		int pay, count;

		while (tmp != 3) {

		cout << "����� ������ �ּ���. (1. ���� ���� 2. ������Ȳ ���� ��� 3. ������) : ";
		cin >> tmp;


			if (tmp == 1) {

				cout << "������ ������ �Է��� �ּ���. (�Է� ���� : 500 2 -> 500�� ¥�� 2��) : ";
				cin >> pay >> count;

				switch (pay) {
				case 500:
					coinChanger->plusCoin500(count);
					break;
				case 100:
					coinChanger->plusCoin100(count);
					break;
				case 50:
					coinChanger->plusCoin50(count);
					break;
				case 10:
					coinChanger->plusCoin10(count);
					break;
				default:
					cout << "�߸��� ���� �� �Դϴ�." << endl;
					break;
				}

			}
			else if (tmp == 2) {
				// ���� ��Ȳ ���� ���.
				// ���� ����� ����, ���� ����, ������ ����, ���� �� ����
				cout << endl;
				cout << "���� �Ǹ� �ݾ��� : " << this->sell_total << "�� �Դϴ�. " << endl;
				
				cout << "---------- �Ǹ��� ����� ���� -----------" << endl;
				cout << "�ݶ� : " << this->sell_menu[0] << " ��" << endl;
				cout << "���̴� : " << this->sell_menu[1] << " ��" << endl;
				cout << "�꽺 : " << this->sell_menu[2] << " ��" << endl;


				cout << "---------- ���� ����� ���� -----------" << endl;
				cout << "�ݶ� : " << this->Cola->getCount() << " ��" << endl;
				cout << "���̴� : " << this->Cider->getCount() << " ��" << endl;
				cout << "�꽺 : " << this->Juice->getCount() << " ��" << endl;

				cout << endl;

				cout << "---------- ���� ���� �� ���� ���� -----------" << endl;
				cout << "1000�� : " << this->bill_1000 << " ��" << endl;
				cout << "500�� : " << this->coinChanger->getCount500() << " ��" << endl;
				cout << "100�� : " << this->coinChanger->getCount100() << " ��" << endl;
				cout << "50�� : " << this->coinChanger->getCount50() << " ��" << endl;
				cout << "10�� : " << this->coinChanger->getCount10() << " ��" << endl;

			}
		}

		this->start();

	}

};


int main() {

	VendingMachine v1;

	v1.start();

}