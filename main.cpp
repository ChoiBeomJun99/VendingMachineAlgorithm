#include<iostream>
#include<string>

using namespace std;

class Money { //돈에 대한 클래스이다.
protected:

	// 각 단위에 해당하는 돈은 개수를 의미한다.
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
	// total은 객체가 가진 총 돈의 총액을 나타낸다.
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

class Menu { //메뉴에 대한 클래스이다.
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

class VendingMachine { //자판기에 대한 클래스이다.
private:

	//자판기가 가지고 있는 거스름돈을 위한 각 동전 개수 음료수의 값들을 초기화 해준다.
	Hopper *coinChanger;
	int bill_1000 = 0; //1000원 짜리 지폐의 개수

	Menu *Cola;
	Menu *Cider;
	Menu *Juice;

	
	int sell_menu[3] = { 0, 0, 0 }; //각 메뉴를 판매한 개수
	int sell_total=0 ; //판매금액
	int input_total; // 사용자가 넣은 금액
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
		cout << "-----------거스름 돈 결과------------" << endl;
		cout << "500원 짜리 :  " << arrayCoinCount[0] << " 개 " << endl;
		cout << "100원 짜리 :  " << arrayCoinCount[1] << " 개 " << endl;
		cout << "50원 짜리 :  " << arrayCoinCount[2] << " 개 " << endl;
		cout << "10원 짜리 :  " << arrayCoinCount[3] << " 개 " << endl;
		cout << "총 " << result << " 원" << endl;
		this->input_total -= result;

	}

	void plusBill1000(int hap) {
		this->bill_1000 += hap;
	}

	void buy(int input_total, int menu) {

		switch (menu) {
			case 1:
				if ((this->input_total >= this->Cola->getCost()) && (this->Cola->getCount() > 0)) {

					cout << "콜라를 구입하였습니다." << endl;
					this->sell_menu[0] += 1;
					this->input_total -= Cola->getCost();
					this->sell_total += Cola->getCost();
					Cola->minusCount();
					break;
				}
				else {
					cout << "금액이 부족하거나 콜라의 개수가 부족합니다. " << endl;
					break;
				}

			case 2:
				if ((this->input_total >= this->Cider->getCost()) && (this->Cider->getCount() > 0)) {

					cout << "사이다를 구입하였습니다." << endl;
					this->sell_menu[1] += 1;
					this->sell_total += Cider->getCost();
					this->input_total -= Cider->getCost();
					Cider->minusCount();
					break;
				}
				else {
					cout << "금액이 부족하거나 사이다의 개수가 부족합니다. " << endl;
					break;
				}

			case 3:
				if ((this->input_total >= this->Juice->getCost()) && (this->Juice->getCount() > 0)) {
					cout << "주스를 구입하였습니다." << endl;
					this->sell_menu[2] += 1;
					this->sell_total += Juice->getCost();
					this->input_total -= Juice->getCost();
					Juice->minusCount();
					break;
				}
				else {
					cout << "금액이 부족하거나 주스의 개수가 부족합니다. " << endl;
					break;
				}

			default:
				cout << " 잘못된 번호 입니다. " << endl;
				break;
		}
	}

	void start() { //시작 기능

		int tmp;
		
		if (this->coinChanger->getTotal() > 1500) { // 거스름돈을 줄 수 있는 조건에 부합하지 못한다면 사용중지 한다.
			
			cout << "자판기 기능 선택 (1.운영 2.유지보수 3.나가기) : ";
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
				cout << "잘못된 입력입니다." << endl;
			}
		}
		else {
			cout << endl;
			cout << "거스름돈 부족으로 인한 운영 불가" << endl;
			return;
		}

		

	}

	void operating() { //운영 기능

		int tmp = 0;
		int pay, count;
		int total = 0;


		while (tmp != 3) {
			cout << endl;
			cout << "지폐 혹은 동전을 투입 하십시오. (현재 투입 된 돈 : "<< this->input_total << " 원 " << "1. 지폐 투입, 2. 동전 투입, 3. 투입 그만하기 : ";
			cin >> tmp;

			if (tmp == 1) {
				cout << endl;
				cout << "지폐를 투입해 주세요 1000원 짜리만 가능 (입력 예시 : 2 -> 1000원 짜리 2장) : ";
				cin >> count;
				this->plusBill1000(count);

				this->input_total += 1000 * count;
			}
			else if (tmp == 2) {
				cout << endl;
				cout << "동전을 투입해 주세요 (입력 예시 : 500 2 -> 500원 짜리 2개) : ";
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
					cout << "잘못된 동전 값 입니다." << endl;
					break;
				}
			}


		}

		while (tmp != 4) {
			cout << endl;
			cout << "어떤 음료를 구입하시겠습니까? ( 남은 금액 : " << this->input_total << " ) \n" << "1. 콜라(1000원) 2. 사이다(1200원) 3. 쥬스(1500원) 4. 그만 구입하기 (거스름 돈 받기) : ";
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

	void maintenance() { //유지보수 기능 

		int tmp = 0;
		int pay, count;

		while (tmp != 3) {

		cout << "기능을 선택해 주세요. (1. 동전 보급 2. 매출현황 보고서 출력 3. 나가기) : ";
		cin >> tmp;


			if (tmp == 1) {

				cout << "보급할 동전을 입력해 주세요. (입력 예시 : 500 2 -> 500원 짜리 2개) : ";
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
					cout << "잘못된 동전 값 입니다." << endl;
					break;
				}

			}
			else if (tmp == 2) {
				// 매출 현황 보고서 출력.
				// 남은 음료수 개수, 남은 동전, 지폐의 개수, 금일 총 매출
				cout << endl;
				cout << "금일 판매 금액은 : " << this->sell_total << "원 입니다. " << endl;
				
				cout << "---------- 판매한 음료수 개수 -----------" << endl;
				cout << "콜라 : " << this->sell_menu[0] << " 개" << endl;
				cout << "사이다 : " << this->sell_menu[1] << " 개" << endl;
				cout << "쥬스 : " << this->sell_menu[2] << " 개" << endl;


				cout << "---------- 남은 음료수 개수 -----------" << endl;
				cout << "콜라 : " << this->Cola->getCount() << " 개" << endl;
				cout << "사이다 : " << this->Cider->getCount() << " 개" << endl;
				cout << "쥬스 : " << this->Juice->getCount() << " 개" << endl;

				cout << endl;

				cout << "---------- 남은 동전 및 지폐 개수 -----------" << endl;
				cout << "1000원 : " << this->bill_1000 << " 장" << endl;
				cout << "500원 : " << this->coinChanger->getCount500() << " 개" << endl;
				cout << "100원 : " << this->coinChanger->getCount100() << " 개" << endl;
				cout << "50원 : " << this->coinChanger->getCount50() << " 개" << endl;
				cout << "10원 : " << this->coinChanger->getCount10() << " 개" << endl;

			}
		}

		this->start();

	}

};


int main() {

	VendingMachine v1;

	v1.start();

}