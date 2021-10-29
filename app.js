import React from 'react';
import { Image, LogBox } from 'react-native';
import AppLoading from 'expo-app-loading';
import ns from './navigation/Screens';
import { Images, Theme } from './constants';
import { store } from './redux/store';
import AsyncStorage from '@react-native-async-storage/async-storage';
import globalConfig from './global'


// cache app images
const assetImages = [
  Images.Onboarding,
  Images.Logo
];

export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      isLoadingComplete: false,
      fontLoaded: false,
    };
  }

  componentDidMount() {
    LogBox.ignoreLogs(['VirtualizedLists should never be nested']);
    this.getData()
  }
  getData=async()=>{
  await AsyncStorage.getItem('headerToken').then((item)=>{
    console.log("token=====",item)
     item&&
     globalConfig.setToken(item)
   })
  }

  render() {
    if (!this.state.isLoadingComplete) {
      return (
        <AppLoading
          startAsync={this._loadResourcesAsync}
          onError={this._handleLoadingError}
          onFinish={this._handleFinishLoading}
        />
      );
    } else {
      return (
        <>
          <Provider store={store}>
            <NavigationContainer>
              <GalioProvider theme={Theme}>
                <Block flex>
                  <Screens />
                </Block>
              </GalioProvider>
            </NavigationContainer>
          </Provider>

          <Toast ref={(ref) => Toast.setRef(ref)} />
        </>
      );
    }
  }

  // _loadResourcesAsync = async () => {
  //   await Font.loadAsync({
  //     'roboto-regular': require('./assets/font/Roboto-Regular.ttf'),
  //     'roboto-bold': require('./assets/font/Roboto-Bold.ttf')
  //   });

  //   this.setState({ fontLoaded: true });
  //   return Promise.all([...cacheImages(assetImages)]);
  // };

  _handleFinishLoading = () => {
    if (this.state.fontLoaded) {
      this.setState({ isLoadingComplete: true });
    }
  };
}
